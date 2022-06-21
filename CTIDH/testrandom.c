#include <stdlib.h>
#include <assert.h>
#include "random.h"

void test_random_coin(void)
{
  uint64_t dist[2];
  uint64_t loop;

  for (uint64_t den = 1;den <= 10;++den) {
    for (uint64_t num = 0;num <= den;++num) {
      dist[0] = dist[1] = 0;
      for (loop = 0;loop < 16384*den;++loop) {
        int64_t r = random_coin(num,den);
        assert(r <= 0);
        assert(r >= -1);
        ++dist[-r];
      }
      assert(dist[0]+dist[1] == loop);
      if (num == 0) {
        assert(dist[1] == 0);
      } else if (num == den) {
        assert(dist[1] == loop);
      } else {
        assert(dist[1] > (16384-1536)*num);
        assert(dist[1] < (16384+1536)*num);
      }
    }
  }
}

void test_boundedl1_2(void)
{
  long long dist[11][11];
  int8_t e[4];
  long long table[6] = {1,5,13,25,41,61};

  for (long long S = 0;S <= 5;++S) {
    for (long long i = 0;i < 11;++i)
      for (long long j = 0;j < 11;++j)
        dist[i][j] = 0;

    for (long long loop = 0;loop < table[S]*16384;++loop) {
      e[0] = loop;
      e[3] = loop;
      random_boundedl1(e+1,2,S);
      assert(e[0] == (int8_t) loop);
      assert(e[3] == (int8_t) loop);
      assert(abs(e[1])+abs(e[2]) <= S);
      ++dist[e[1]+S][e[2]+S];
    }

    long long numnonzero = 0;
    long long maxnonzero = 0;
    long long minnonzero = 0;

    for (long long i = 0;i < 11;++i)
      for (long long j = 0;j < 11;++j) {
        long long expected = llabs(i-S)+llabs(j-S)<=S;
        long long D = dist[i][j];
        if (D) {
          if (!numnonzero)
            maxnonzero = minnonzero = D;
          else {
            if (D > maxnonzero) maxnonzero = D;
            if (D < minnonzero) minnonzero = D;
          }
          ++numnonzero;
          assert(expected);
        } else {
          assert(!expected);
        }
      }

    assert(minnonzero >= 16384-1536);
    assert(maxnonzero <= 16384+1536);
  }
}

void test_boundedl1_3(void)
{
  long long dist[11][11][11];
  int8_t e[5];
  long long table[6] = {1,7,25,63,129,231};

  for (long long S = 0;S <= 5;++S) {
    for (long long i = 0;i < 11;++i)
      for (long long j = 0;j < 11;++j)
        for (long long k = 0;k < 11;++k)
          dist[i][j][k] = 0;

    for (long long loop = 0;loop < table[S]*16384;++loop) {
      e[0] = loop;
      e[4] = loop;
      random_boundedl1(e+1,3,S);
      assert(e[0] == (int8_t) loop);
      assert(e[4] == (int8_t) loop);
      assert(abs(e[1])+abs(e[2])+abs(e[3]) <= S);
      ++dist[e[1]+S][e[2]+S][e[3]+S];
    }

    long long numnonzero = 0;
    long long maxnonzero = 0;
    long long minnonzero = 0;

    for (long long i = 0;i < 11;++i)
      for (long long j = 0;j < 11;++j)
        for (long long k = 0;k < 11;++k) {
          long long expected = llabs(i-S)+llabs(j-S)+llabs(k-S)<=S;
          long long D = dist[i][j][k];
          if (D) {
            if (!numnonzero)
              maxnonzero = minnonzero = D;
            else {
              if (D > maxnonzero) maxnonzero = D;
              if (D < minnonzero) minnonzero = D;
            }
            ++numnonzero;
            assert(expected);
          } else {
            assert(!expected);
          }
        }

    assert(minnonzero >= 16384-1536);
    assert(maxnonzero <= 16384+1536);
  }
}

int main()
{
  test_random_coin();
  test_boundedl1_2();
  test_boundedl1_3();
  return 0;
}
