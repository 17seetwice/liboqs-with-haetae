#include "fips202.h"
#include "params.h"
#include "symmetric.h"
#include <stdint.h>

void haetae_shake128_stream_init(shake128incctx *state,
                                 const uint8_t seed[SEEDBYTES],
                                 uint16_t nonce) {
    uint8_t t[2];
    t[0] = nonce;
    t[1] = nonce >> 8;

    shake128_inc_init(state);
    shake128_inc_absorb(state, seed, SEEDBYTES);
    shake128_inc_absorb(state, t, 2);
    shake128_inc_finalize(state);
}

void haetae_shake256_stream_init(shake256incctx *state,
                                 const uint8_t seed[CRHBYTES], uint16_t nonce) {
    uint8_t t[2];
    t[0] = nonce;
    t[1] = nonce >> 8;

    shake256_inc_init(state);
    shake256_inc_absorb(state, seed, CRHBYTES);
    shake256_inc_absorb(state, t, 2);
    shake256_inc_finalize(state);
}

void haetae_shake256_absorb_twice(shake256incctx *state, const uint8_t *in1,
                                  size_t in1len, const uint8_t *in2,
                                  size_t in2len) {
    shake256_inc_init(state);
    shake256_inc_absorb(state, in1, in1len);
    shake256_inc_absorb(state, in2, in2len);
    shake256_inc_finalize(state);
}
