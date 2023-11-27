
#include <optimizer_toolkit.hh>
#include <immintrin.h> // for AVX
#include <xmmintrin.h> // for SSE

namespace optkit::examples
{

    // Function to perform addition using SSE
    void add__sse(float *a, float *b, float *result, int size)
    {
        __m128 *xmm_a = reinterpret_cast<__m128 *>(a);
        __m128 *xmm_b = reinterpret_cast<__m128 *>(b);
        __m128 *xmm_result = reinterpret_cast<__m128 *>(result);

        for (int i = 0; i < size / 4; ++i)
        {
            xmm_result[i] = _mm_add_ps(xmm_a[i], xmm_b[i]);
        }
    }

    // Function to perform addition using AVX
    void add__avx(float *a, float *b, float *result, int size)
    {
        __m256 *ymm_a = reinterpret_cast<__m256 *>(a);
        __m256 *ymm_b = reinterpret_cast<__m256 *>(b);
        __m256 *ymm_result = reinterpret_cast<__m256 *>(result);

        for (int i = 0; i < size / 8; ++i)
        {
            ymm_result[i] = _mm256_add_ps(ymm_a[i], ymm_b[i]);
        }
    }
    // Function to perform addition in a serial manner
    void add__serial(float *a, float *b, float *result, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            result[i] = a[i] + b[i];
        }
    }

    void example__sse_avx_loop_comparison()
    {
        const int ARRAY_SIZE = 16;
        float aa[ARRAY_SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
        float bb[ARRAY_SIZE] = {16.0, 15.0, 14.0, 13.0, 12.0, 11.0, 10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
        float result_sse[ARRAY_SIZE];
        float result_avx[ARRAY_SIZE];
        float result_serial[ARRAY_SIZE];

        std::cout << "========= EMPTY ===========" << std::endl;

        {
            OPTKIT_RAPL_REPEAT(add_sse, Add SSE, 1000000)
            {
                // do nothing
            }
        }

        std::cout << "========= SSE ===========" << std::endl;

        {
            OPTKIT_RAPL_REPEAT(add_sse, Add SSE, 1000000)
            {
                add__sse(aa, bb, result_sse, ARRAY_SIZE);
            }
        }

        std::cout << "========= AVX ===========" << std::endl;

        {
            OPTKIT_RAPL_REPEAT(add_avx, Add AVX, 1000000)

            {
                add__avx(aa, bb, result_avx, ARRAY_SIZE);
            }
        }

        std::cout << "========= SERIAL =========" << std::endl;

        {
            OPTKIT_RAPL_REPEAT(add_serial, Add SERIAL, 1000000)
            {
                add__serial(aa, bb, result_serial, ARRAY_SIZE);
            }
        }

        std::cout << "========== DONE ==========\n";
    }
} // namespace optkit::examples
