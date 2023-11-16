#include <omp.h>
#include <optimizer_toolkit.hh>
#include <intel/icl.hh>

#define STREAM_ARRAY_SIZE 100000 // 100k

double a[100000];
double b[100000];
double c[100000];
int scalar = 3;

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    std::cout << optkit::core::Query::detect_packages();
    exit(0);

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