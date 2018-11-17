#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>

double a[4000][4000];
double b[4000][4000];
double c[4000][4000];

int main(int argc, char * argv[])
{
  int N;
  int i, j, k;

  if (argc > 1) N = atoi(argv[1]);
  else N = 100;

  for (i=0 ;i<N; i++)  
    for (j=0 ;j<N; j++) {
      c[i][j] = 0;
      a[i][j] = drand48();
      b[i][j] = drand48();
    }

  for (i=0; i<N; i++) 
    for (j=0; j<N; j++) 
      for (k=0; k<N; k++) c[i][j] = c[i][j] + a[i][k]*b[k][j];

#ifdef VERBOSE
  for (i=0; i<N; i++) 
    for (j=0; j<N; j++) 
      printf("C[%d][%d] = %f\n", i, j, c[i][j]);
#endif  
}
 

    
    
