#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <signal.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <sys/mman.h>

#define MMAP_PAGES 8
static int fd1;
static int total;

std::vector<std::chrono::high_resolution_clock::time_point> timee;

static void our_handler(int signum, siginfo_t *oh, void *blah)
{

    timee.push_back(std::chrono::high_resolution_clock::now());

    int ret;

    ret = ioctl(fd1, PERF_EVENT_IOC_DISABLE, 0);

    total++;

    ret = ioctl(fd1, PERF_EVENT_IOC_ENABLE, 1);

    (void)ret;
}

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};

    BLOCK_TIMER("main");

    struct perf_event_attr pe;
    struct sigaction sa;
    void *our_mmap;

    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_sigaction = our_handler;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGIO, &sa, NULL) < 0)
    {
        fprintf(stderr, "Error setting up signal handler\n");
        exit(1);
    }
    memset(&pe, 0, sizeof(struct perf_event_attr));

    pe.type = PERF_TYPE_RAW;
    pe.size = sizeof(struct perf_event_attr);

    pe.config = 0xc0; // retired instr

    pe.sample_period = 3300000; // set current freq in khz in files (scaling_max_freq) to sample each 1ms * 10 to get ~10ms
    pe.sample_type = PERF_SAMPLE_RAW;
    pe.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;
    pe.exclude_kernel = 1;
    pe.exclude_hv = 1;
    

    fd1 = syscall(__NR_perf_event_open, &pe, 0, -1, -1, 0);
    if (fd1 < 0)
    {
        fprintf(stderr, "Error opening leader %llx\n", pe.config);
    }

    our_mmap = mmap(NULL, (1 + MMAP_PAGES) * getpagesize(),
                    PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);

    fcntl(fd1, F_SETFL, O_RDWR | O_NONBLOCK | O_ASYNC);
    fcntl(fd1, F_SETSIG, SIGIO);
    fcntl(fd1, F_SETOWN, getpid());

    ioctl(fd1, PERF_EVENT_IOC_RESET, 0);
    int ret = ioctl(fd1, PERF_EVENT_IOC_ENABLE, 0);
    if (ret < 0)
    {
        fprintf(stderr, "Error with PERF_EVENT_IOC_ENABLE of group leader: "
                        "%d %s\n",
                errno, strerror(errno));
    }

    {
        // BlockProfiler variable_name{"for_loop", "Computational Intensity", recepies::intel::icl::Recepies::computational_intensity()};
        double aa = 0;

        for (int i = 0; i < 50000000; i++)
            aa = aa + i * 0.052; // 2M

        // std::cout << aa << "\n";
    }

    close(fd1);
    fprintf(stderr, "number of samples: %d\n", total);

    std::cout << "call_ref: " << std::chrono::duration_cast<std::chrono::microseconds>(timee.at(1) - timee.at(0)).count() / 1000.0f << std::endl;
    std::cout << "call_ref: " << std::chrono::duration_cast<std::chrono::microseconds>(timee.at(2) - timee.at(1)).count() / 1000.0f << std::endl;
    std::cout << "call_ref: " << std::chrono::duration_cast<std::chrono::microseconds>(timee.at(3) - timee.at(2)).count() / 1000.0f << std::endl;
    std::cout << "call_ref: " << std::chrono::duration_cast<std::chrono::microseconds>(timee.at(4) - timee.at(3)).count() / 1000.0f << std::endl;

    return 0;
}
