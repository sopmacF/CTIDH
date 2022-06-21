// DO NOT EDIT! generated by ./autogen

#include "primes.h"

// number of keys: 116521449661531114383380223746284575519929319593782349198434372885969796484375
// approximately 2^256.009059

// average costs (calculated):
// mults 437985.551160 AB 18.981487 elligator 37.962975 clear2 75.925950 isog0 0.118343 0.092238 0.061913 0.079227 0.036343 0.016390 0.127503 0.109749 0.094409 0.085079 4.970532 0.044207 12.001320 1.000000 isog1 0.047654 0.051857 0.043724 0.053524 0.024901 0.011500 0.057482 0.031896 4.902102 4.979184 12.031918 12.955793 0.998680 0.000000 isog2 9.834003 13.855905 15.894363 16.867249 16.938756 16.972110 17.815015 17.858355 13.003489 12.935737 0.997550 0.000000 0.000000 0.000000 maxdac 203.058777 237.252515 263.740061 253.987054 269.708994 251.133712 281.141637 298.936065 311.894078 304.086797 441.218681 167.956623 328.682981 13.022184 eachdac 7.962975 5.296308 3.962975 2.829642 3.223845 3.477261 1.587975 1.677261 1.740753 1.779301 1.812975 11.870776 11.884187 35.959562

// average costs (4096 simulated trials):
// mults 438036.479492 AB 18.987549 elligator 37.975098 clear2 75.950195 isog0 0.121582 0.085938 0.063721 0.072510 0.036377 0.014160 0.138672 0.102783 0.097168 0.091309 4.972412 0.049805 11.999512 1.000000 isog1 0.044922 0.054932 0.043701 0.052490 0.025879 0.011475 0.066406 0.028076 4.899902 4.977539 12.029053 12.950195 1.000488 0.000000 isog2 9.833496 13.859131 15.892578 16.875000 16.937744 16.974365 17.794922 17.869141 13.002930 12.931152 0.998535 0.000000 0.000000 0.000000 maxdac 202.852295 236.944092 264.081299 253.992188 269.697754 251.060303 281.375244 298.808105 311.884277 304.177246 441.173584 168.064453 328.546387 13.031738 eachdac 7.991211 5.366211 3.920410 2.845703 3.237305 3.502441 1.558105 1.709961 1.752441 1.780762 1.826172 11.874023 11.906250 35.970215

const long long primes[primes_num] = {
  3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 587,
};

const long long primes_dac[primes_num] = {
  0, 0, 2, 4, 0, 10, 4, 24, 16, 8, 48, 42, 34, 32, 106, 88, 81, 72, 80, 20, 16, 210, 0, 192, 164, 48, 96, 132, 464, 417, 64, 424, 388, 416, 180, 384, 296, 266, 192, 272, 258, 136, 130, 785, 256, 788, 708, 776, 784, 0, 682, 832, 554, 641, 592, 552, 648, 672, 328, 576, 514, 264, 160, 80, 320, 1704, 32, 1384, 1448, 1424, 1600, 1410, 1354, 2832,
};

const long long primes_daclen[primes_num] = {
  0, 1, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 7, 8, 8, 8, 8, 8, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 9, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 10, 11, 11, 11, 11, 11, 11, 12,
};

const long long primes_batchsize[primes_batches] = {
  2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 6, 8, 1,
};

const long long primes_batchstart[primes_batches] = {
  0, 2, 5, 9, 13, 18, 23, 29, 36, 43, 51, 59, 65, 73,
};

const long long primes_batchstop[primes_batches] = {
  2, 5, 9, 13, 18, 23, 29, 36, 43, 51, 59, 65, 73, 74,
};

const long long primes_batchmaxdaclen[primes_batches] = {
  1, 3, 5, 6, 7, 8, 9, 9, 9, 10, 10, 10, 11, 12,
};

const long long primes_batchbound[primes_batches] = {
  10, 14, 16, 17, 17, 17, 18, 18, 18, 18, 18, 13, 13, 1,
};