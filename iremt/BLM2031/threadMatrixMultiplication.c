#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define M 3
#define K 2
#define N 3

int A [M][K] = { {1,4}, {2,5}, {3,6} };
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];
struct v {
   int i; /* satir */
   int j; /* sutun */
};
void *threadedMult(void *param); 
int main() {
   int i,j;
        
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
      	 struct v *data = (struct v *) malloc(sizeof(struct v)); //satir ve stun bilgisi bir structure yapisinda tutulmali
         data->i = i;
         data->j = j;
         pthread_t tid;       //Thread ID tanýmlanýr
         pthread_create(&tid,NULL,threadedMult,(void*)data); // thread olusturulur. threadedMult fonksiyonu parametre olarak (void*)'a cast edilmis datayi alir 
         pthread_join(tid, NULL); //thread beklenir
        //sleep(2); 
        }
   }
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}

//matris carpimi icin worker fonksiyon
void *threadedMult(void *param) {
   struct v *data = (struct v *)param; 
   int n, sum = 0; 
   for(n = 0; n< K; n++){
      sum += A[data->i][n] * B[n][data->j];
   }
   C[data->i][data->j] = sum;
   pthread_exit(0);
}
//sequential matris carpimi 
void sequentialMult()
{
	int sum=0;
	int i,j,k;
	for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++) {
        for (k = 0; k < K; k++) {
          sum = sum + A[i][k]*B[k][j];
        }
        C[i][j] = sum;
        sum = 0;
      }
    }
}
