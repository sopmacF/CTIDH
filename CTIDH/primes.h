// DO NOT EDIT! generated by ./autogen

#ifndef primes_h
#define primes_h

#include "primes_namespace.h"

#if BITS == 511
#define primes_num 74
#define primes_batches 15
#define primes_maxbatchboundplussize 20
#elif BITS == 512
#define primes_num 74
#define primes_batches 14
#define primes_maxbatchboundplussize 26
#elif BITS == 1024
#define primes_num 130
#define primes_batches 17
#define primes_maxbatchboundplussize 19
#else
#error BITS must be 511 or 512 or 1024
#endif

extern const long long primes[primes_num];
extern const long long primes_dac[primes_num];
extern const long long primes_daclen[primes_num];
extern const long long primes_batchsize[primes_batches];
extern const long long primes_batchstart[primes_batches];
extern const long long primes_batchstop[primes_batches];
extern const long long primes_batchbound[primes_batches];
extern const long long primes_batchmaxdaclen[primes_batches];

#endif
