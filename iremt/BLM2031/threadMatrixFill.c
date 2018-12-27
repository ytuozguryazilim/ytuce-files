#include <pthread.h>
#include <stdio.h>
#define N 10
#define M 10
int A [N][M];
int step=0; //tum threadlerin erisecegi global degisken 
//worker fonksiyon
void *runner()
{
   int m;
   int core=step++; //her thread step degiskenini bir arttirir ve siradaki satira erisir
   for(m = 0; m< M; m++)
      A[core][m]=m+1; //ilgili hucre doldurulur
   pthread_exit(0);
}
int main()
{
	int i=0,j;
	pthread_t tid[N]; 
	for(i = 0; i < N; i++) {
         pthread_attr_t attr; //thread ozelliklerini saklayacak degisken tanimlanir
         pthread_attr_init(&attr);//varsayilan ozellikler alinir
         pthread_create(&tid[i],&attr,runner,NULL); //thread olusturulur
         //pthread_create(&tid[i],&attr,&runner,NULL); //bu sekilde de olabilir
    }
	//tum threadler beklenir
   for(i = 0; i < N; i++) 
    	pthread_join(tid[i], NULL);
   //sonuc matrisi yazilir
   for(i = 0; i < N; i++) {
      for(j = 0; j < M; j++) 
         printf("%d ", A[i][j]);
      printf("\n");
   }
}

