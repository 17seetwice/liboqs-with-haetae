#ifndef API_H
#define API_H

#include <stddef.h>
#include <stdint.h>

#define haetae2_PUBLICKEYBYTES 992
#define haetae2_SECRETKEYBYTES 1408
#define haetae2_BYTES 1474


int haetae2_keypair(uint8_t *pk, uint8_t *sk);

int haetae2_signature(uint8_t *sig, size_t *siglen,
                                        const uint8_t *m, size_t mlen,
                                        const uint8_t *sk);

int haetae2_ref(uint8_t *sm, size_t *smlen,
                              const uint8_t *m, size_t mlen,
                              const uint8_t *sk);

int haetae2_verify(const uint8_t *sig, size_t siglen,
                                     const uint8_t *m, size_t mlen,
                                     const uint8_t *pk);

int haetae2_open(uint8_t *m, size_t *mlen,
                                   const uint8_t *sm, size_t smlen,
                                   const uint8_t *pk);

#define haetae3_PUBLICKEYBYTES 1472
#define haetae3_SECRETKEYBYTES 2112
#define haetae3_BYTES 2349


int haetae3_keypair(uint8_t *pk, uint8_t *sk);

int haetae3_signature(uint8_t *sig, size_t *siglen,
                                        const uint8_t *m, size_t mlen,
                                        const uint8_t *sk);

int haetae3_ref(uint8_t *sm, size_t *smlen,
                              const uint8_t *m, size_t mlen,
                              const uint8_t *sk);

int haetae3_verify(const uint8_t *sig, size_t siglen,
                                     const uint8_t *m, size_t mlen,
                                     const uint8_t *pk);

int haetae3_open(uint8_t *m, size_t *mlen,
                                   const uint8_t *sm, size_t smlen,
                                   const uint8_t *pk);      
                                   
#define haetae5_PUBLICKEYBYTES 2080
#define haetae5_SECRETKEYBYTES 2752
#define haetae5_BYTES 2948


int haetae5_keypair(uint8_t *pk, uint8_t *sk);

int haetae5_signature(uint8_t *sig, size_t *siglen,
                                        const uint8_t *m, size_t mlen,
                                        const uint8_t *sk);

int haetae5_ref(uint8_t *sm, size_t *smlen,
                              const uint8_t *m, size_t mlen,
                              const uint8_t *sk);

int haetae5_verify(const uint8_t *sig, size_t siglen,
                                     const uint8_t *m, size_t mlen,
                                     const uint8_t *pk);

int haetae5_open(uint8_t *m, size_t *mlen,
                                   const uint8_t *sm, size_t smlen,
                                   const uint8_t *pk);   



#endif
