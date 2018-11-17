#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double a[4000][4000];
double b[4000][4000];
double c[4000][4000];
int N;

int Nthreads;

int myid[200];
pthread_t tid[200];

void *mymm(void *arg) {
  int myrank;
  int i, j, k;
  myrank = *(int *)arg;
  for (i=0; i<N; i++)
    for (j=N/Nthreads*myrank; j < N/Nthreads*(myrank+1)-1; j++)
      for (k=0; k<N; k++)
	c[i][j] = c[i][j] + a[i][k]*b[k][j];
}

int main(int argc, char * argv[])
{
  int i, j, k;

  if (argc > 2) {N = atoi(argv[2]); Nthreads = atoi(argv[1]);}
  else if (argc > 1) {N = 100; Nthreads = atoi(argv[1]);}
  else {N= 100; Nthreads = 1;}
    
  for (i=0; i<Nthreads; i++) {
    myid[i] = i;
    pthread_create(&tid[i], NULL, &mymm, &myid[i]);
  } 

  for (i=0; i<Nthreads; i++) {
    pthread_join(tid[i], NULL);
  } 
  return 0;
}
 

    
    
