/* { dg-do run { target { riscv_v } } } */
/* { dg-additional-options "-mrvv-vector-bits=scalable -fno-vect-cost-model" } */

#include "cond_arith-7.c"

#define N 98

#undef TEST
#define TEST(TYPE, NAME, OP)					\
  {								\
    TYPE x[N], y[N], pred[N], z[2] = { 5, 7 };			\
    for (int i = 0; i < N; ++i)					\
      {								\
	y[i] = i * i;						\
	pred[i] = i % 3;					\
      }								\
    test_##TYPE##_##NAME (x, y, z[0], z[1], pred, N);		\
    for (int i = 0; i < N; ++i)					\
      {								\
	TYPE expected = i % 3 != 1 ? y[i] OP z[i & 1] : y[i];	\
	if (x[i] != expected)					\
	  __builtin_abort ();					\
	asm volatile ("" ::: "memory");				\
      }								\
  }

int
main (void)
{
  TEST_ALL
  return 0;
}
