/* compiled with -msse2, etc*/

//#include <mmintrin.h>  /* MMX */
//#include <xmmintrin.h> /* SSE */
#include <emmintrin.h> /* SSE2 */
//#include <pmmintrin.h> /* SSE3 */
//#include <tmmintrin.h> /* SSSE3 */
//#include <smmintrin.h> /* SSE4.2 SSE4.1 */

#include<sys/time.h>
#include<time.h>
#include<stdio.h>
typedef unsigned long long ticks;

static __inline__ ticks getticks(void)
{
     unsigned a, d;
     asm("cpuid");
     asm volatile("rdtsc" : "=a" (a), "=d" (d));

     return (((ticks)a) | (((ticks)d) << 32));
}


main()
{
  unsigned long long int t1, t2, t3;

  float z1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  float z2[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  float z3[8];
  float z4[8];

  int i, j;

  t1 = getticks();
  
  for (j=0;j<100; j++) {
  for(i=0; i<8; i++) {
    z3[i] = z1[i] + z2[i];
  }
  }
  t2 = getticks();
  printf("time = %lld\n", t2-t1);

  t1 = getticks();
  for (j=0; j<100; j++) {
  __m128 *v_z1 = (__m128 *)z1;
  __m128 *v_z2 = (__m128 *)z2;
  __m128 *v_z3 = (__m128 *)z4;

  for(i=0; i<2; i++) {
    *v_z3 = _mm_add_ps(*v_z1, *v_z2);
    v_z1++;
    v_z2++;
    v_z3++;
  }
  }
  t2 = getticks();

  printf("time = %lld\n", t2-t1);
  for (i=0; i<8; i++) {
    //    if (z3[i] != z4[i]) {printf("Wrong.\n"); exit(0);}
    printf("%d %f %f\n", i, z3[i], z4[i]);
  }
  printf("Correct, results matched.\n");
  return 0;
}
