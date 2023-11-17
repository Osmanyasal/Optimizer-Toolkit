#include <omp.h>
#include <optimizer_toolkit.hh>
#include <intel/icl.hh>
#include <unistd.h>

#define STREAM_ARRAY_SIZE 100000 // 100k

double a[100000];
double b[100000];
double c[100000];
int scalar = 3;

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;
    RaplProfiler rapl_profiler{RaplConfig{RaplReadMethods::PERF,(int32_t)RaplDomain::PP0}};
 

    if (Query::is_rapl_perf_avail())
        std::cout << "rapl perf avail!\n";
    if (Query::is_rapl_powercap_avail())
        std::cout << "rapl powercap avail!\n";

    for (int i = 0; i < 100;i++)
    {  
        #define STREAM_ARRAY_SIZE2 10000000 // 10000k
        double *a = new double[STREAM_ARRAY_SIZE2];
        double *b = new double[STREAM_ARRAY_SIZE2];
        double *c = new double[STREAM_ARRAY_SIZE2];
        int scalar = 3;

        for (int j = 0; j < STREAM_ARRAY_SIZE2; j++)
            a[j] = b[j] + scalar * c[j]; // 1 mul 1 addition for scalar double x STREAM_ARRAY_SIZE
    }


    std::cout << Query::detect_packages();

    int32_t paranoid = optkit.paranoid();

    // exit(0);

    {
        float aa = 33;

        // We'll see different numbers due to multiplexing
        BlockGroupProfiler fp_arit{"FP_ARITH", {
                                                   icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_SINGLE,
                                                   icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                               }};
        ssize_t j;

        auto val = fp_arit.read();
        std::cout << "First reading\n";
        std::cout << val[0] << " " << val[1] << std::endl;
        aa += 0.23f;                 // + 1 single
        a[0] = b[0] + scalar * c[0]; // + 2 double

        std::cout << "Second reading\n";
        val = fp_arit.read();
        std::cout << val[0] << " " << val[1] << std::endl;

#pragma omp parallel
        {

            aa += 0.23f; // to scalar single, num_threads x 1
#pragma omp single
            {
                OPTKIT_CORE_INFO("{}/{}", omp_get_thread_num(), omp_get_num_threads());
            }
#pragma omp for
            for (j = 0; j < STREAM_ARRAY_SIZE; j++)
                a[j] = b[j] + scalar * c[j]; // 1 mul 1 addition for scalar double x STREAM_ARRAY_SIZE
        }
    }

    return 0;
}