#ifndef FFT__H
#define FFT__H

#include "poly.h"
#include <stdint.h>
#include "config.h"        /* 이미 포함돼 있다면 중복 추가 X */

#define FFT_N 256
#define FFT_LOGN 8

typedef struct {
    int32_t real;
    int32_t imag;
} complex_fp32_16;

#define fft HAETAE_NAMESPACE(fft)
void fft(complex_fp32_16 data[FFT_N]);

#define fft_init_and_bitrev HAETAE_NAMESPACE(fft_init_and_bitrev)
void fft_init_and_bitrev(complex_fp32_16 r[FFT_N], const poly *x);

#define complex_fp_sqabs HAETAE_NAMESPACE(complex_fp_sqabs)
int32_t complex_fp_sqabs(complex_fp32_16 x);

#endif
