#ifndef SYMMETRIC_H
#define SYMMETRIC_H

#include "params.h"
#include <stdint.h>
#include "fips202.h"        /* <oqs/sha3.h>를 래핑한 shim ── 증분 API 사용 */

/* -------------------------------------------------------------------------- */
/* 1. XOF: SHAKE-256 --------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* 증분 SHAKE-256 컨텍스트 타입 */
typedef shake256incctx xof256_state;

/* 두 입력을 차례로 absorb 하는 사용자 정의 함수 (소스파일에 구현) */
#define haetae_shake256_absorb_twice \
        HAETAE_NAMESPACE(haetae_shake256_absorb_twice)
void haetae_shake256_absorb_twice(shake256incctx *state,
                                  const uint8_t *in1, size_t in1len,
                                  const uint8_t *in2, size_t in2len);

#define XOF256_BLOCKBYTES          SHAKE256_RATE

static inline void xof256_absorb_once_all(shake256incctx *st,
                                          const uint8_t *in,
                                          size_t inlen) {
    shake256_inc_init(st);
    shake256_inc_absorb(st, in, inlen);
    shake256_inc_finalize(st);
}

#undef  xof256_absorbe_once        /* 기존 매크로 삭제 */
#define xof256_absorbe_once  xof256_absorb_once_all

static inline void xof256_absorb_twice_all(shake256incctx *st,
                                           const uint8_t *in1, size_t len1,
                                           const uint8_t *in2, size_t len2) {
    shake256_inc_init(st);
    shake256_inc_absorb(st, in1, len1);
    shake256_inc_absorb(st, in2, len2);
    shake256_inc_finalize(st);
}

#undef  xof256_absorbe_twice
#define xof256_absorbe_twice  xof256_absorb_twice_all


/* squeeze ----------------------------------------------------------------- */
#define xof256_squeeze(OUT, OUT_LEN, STATE) \
        shake256_inc_squeeze(OUT, OUT_LEN, STATE)
#define xof256_squeezeblocks(OUT, OUTBLOCKS, STATE) \
        shake256_squeezeblocks(OUT, OUTBLOCKS, STATE)     /* fips202.h 매크로 */

/* -------------------------------------------------------------------------- */
/* 2. Stream-cipher-like PRNG ------------------------------------------------ */
/*    (AES-256-CTR 기반 또는 SHAKE 기반)                                       */
/* -------------------------------------------------------------------------- */

#ifdef HAETAE_USE_AES      /* ---------- AES-256-CTR 선택 시 ---------------- */

#include "aes256ctr.h"

typedef aes256ctr_ctx  stream128_state;
typedef aes256ctr_ctx  stream256_state;

#define STREAM128_BLOCKBYTES       AES256CTR_BLOCKBYTES
#define STREAM256_BLOCKBYTES       AES256CTR_BLOCKBYTES

#define stream128_init(STATE, SEED, NONCE) \
        aes256ctr_init(STATE, SEED, NONCE)
#define stream128_squeezeblocks(OUT, BLKS, STATE) \
        aes256ctr_squeezeblocks(OUT, BLKS, STATE)

#define stream256_init(STATE, SEED, NONCE) \
        aes256ctr_init(STATE, SEED, NONCE)
#define stream256_squeezeblocks(OUT, BLKS, STATE) \
        aes256ctr_squeezeblocks(OUT, BLKS, STATE)

#else                    /* ---------- SHAKE-128 / SHAKE-256 선택 시 -------- */

typedef shake128incctx stream128_state;
typedef shake256incctx stream256_state;

/* SHAKE-128 기반 스트림 초기화 함수 (별도 소스 구현) */
#define haetae_shake128_stream_init \
        HAETAE_NAMESPACE(haetae_shake128_stream_init)
void haetae_shake128_stream_init(shake128incctx *state,
                                 const uint8_t seed[SEEDBYTES],
                                 uint16_t nonce);

/* SHAKE-256 기반 스트림 초기화 함수 (별도 소스 구현) */
#define haetae_shake256_stream_init \
        HAETAE_NAMESPACE(haetae_shake256_stream_init)
void haetae_shake256_stream_init(shake256incctx *state,
                                 const uint8_t seed[CRHBYTES],
                                 uint16_t nonce);

#define STREAM128_BLOCKBYTES       SHAKE128_RATE
#define STREAM256_BLOCKBYTES       SHAKE256_RATE

#define stream128_init(STATE, SEED, NONCE) \
        haetae_shake128_stream_init(STATE, SEED, NONCE)
#define stream128_squeezeblocks(OUT, BLKS, STATE) \
        shake128_squeezeblocks(OUT, BLKS, STATE)

#define stream256_init(STATE, SEED, NONCE) \
        haetae_shake256_stream_init(STATE, SEED, NONCE)
#define stream256_squeezeblocks(OUT, BLKS, STATE) \
        shake256_squeezeblocks(OUT, BLKS, STATE)

#endif /* HAETAE_USE_AES */

#endif /* SYMMETRIC_H */
