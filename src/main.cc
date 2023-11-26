#include <omp.h>
#include <optimizer_toolkit.hh>
#include <intel/icl.hh>
#include <unistd.h>

#define STREAM_ARRAY_SIZE 100000 // 100k

double a[100000];
double b[100000];
double c[100000];
int scalar = 3;

#define STREAM_ARRAY_SIZE2 10000000 // 10000k
int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

{
    BlockProfiler fp_arit0{"00", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 0}};
    BlockProfiler fp_arit1{"01", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 1}};
    BlockProfiler fp_arit2{"02", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 2}};
    BlockProfiler fp_arit3{"03", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 3}};
    BlockProfiler fp_arit4{"04", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 4}};
    BlockProfiler fp_arit5{"05", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 5}};
    BlockProfiler fp_arit6{"06", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 6}};
    BlockProfiler fp_arit7{"07", {
                                                icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE,
                                            },
                                {true, false, 0, 7}};

    double dd = 0;

    fp_arit7.read_val();
    fp_arit0.read_val();
    fp_arit1.read_val();
    fp_arit2.read_val();
    fp_arit3.read_val();
    fp_arit4.read_val();
    fp_arit5.read_val();
    fp_arit6.read_val();
#pragma omp parallel num_threads(8)
    {
        int th_num = omp_get_thread_num();
        switch (th_num)
        {
        case 0: 
            break;

        case 1: 
            dd++;
            break;

        case 2: 
            dd++;
            dd++;
            break;

        case 3: 
            dd++;
            dd++;
            dd++;
            break;

        case 4: 
            dd++;
            dd++;
            dd++;
            dd++;
            break;

        case 5: 
            dd++;
            dd++;
            dd++;
            dd++;
            dd++;
            break;

        case 6: 
            dd++;
            dd++;
            dd++;
            dd++;
            dd++;
            dd++;
            break;

        case 7: 
            dd++;
            dd++;
            dd++;
            dd++;
            dd++;
            dd++;
            dd++;
            break; 
        default:
            break;
        } 
    }
}

    /*
    {
        OPTKIT_RAPL_FOR(custom_var, custom_block, 10)
        {
            for (int i = 0; i < 10; i++)
            {
                double *a = new double[STREAM_ARRAY_SIZE2];
                double *b = new double[STREAM_ARRAY_SIZE2];
                double *c = new double[STREAM_ARRAY_SIZE2];
                int scalar = 3;

                for (int j = 0; j < STREAM_ARRAY_SIZE2; j++)
                    a[j] = b[j] + scalar * c[j]; // 1 mul 1 addition for scalar double x STREAM_ARRAY_SIZE

                delete[] a;
                delete[] b;
                delete[] c;
            }
            std::cout << custom_var.read_val();
        }
    }
    RaplProfiler rapl_profiler{"main block!"};

    if (Query::is_rapl_perf_avail())
        std::cout
            << "rapl perf avail!\n";
    if (Query::is_rapl_powercap_avail())
        std::cout << "rapl powercap avail!\n";

    for (int i = 0; i < 100; i++)
    {
#define STREAM_ARRAY_SIZE2 10000000 // 10000k
        double *a = new double[STREAM_ARRAY_SIZE2];
        double *b = new double[STREAM_ARRAY_SIZE2];
        double *c = new double[STREAM_ARRAY_SIZE2];
        int scalar = 3;

        for (int j = 0; j < STREAM_ARRAY_SIZE2; j++)
            a[j] = b[j] + scalar * c[j]; // 1 mul 1 addition for scalar double x STREAM_ARRAY_SIZE

        delete[] a;
        delete[] b;
        delete[] c;
    }

    std::cout << Query::detect_packages();

    int32_t paranoid = optkit.paranoid();

    // exit(0);

    {
        float aa = 33;

        // We'll see different numbers due to multiplexing
        BlockProfiler fp_arit{"FP_ARITH", {
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

    std::cout << "READING " << std::endl;
    std::cout << rapl_profiler.read_val();
    */
    return 0;
}