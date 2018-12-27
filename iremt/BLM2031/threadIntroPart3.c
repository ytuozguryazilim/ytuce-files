#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_t tid[2]; //thread idlerini tutan global dizi
int ret1,ret2; //threadlerin donus degerlerini tutran degiskenler
void* worker(void *arg)
{
	pthread_t id = pthread_self();  // aktif thread'in ID'sini dondurur
    if(pthread_equal(id,tid[0]))	// aktif thread'in kacinci thread oldugu kontrol edilir
    {
		printf("I am first tread\n");
		ret1=1;						// return degeri set edilir
		pthread_exit(&ret1);		// pthread_exit() fonksiyonu thread sonlandiginda dondurulecek degiskenin adresini parametre olarak alir
	}
    else
    {
		printf("I am second tread\n");
		ret2=2;
		pthread_exit(&ret2);
	}
}
int main(void)
{
    int i = 0, err;
    int *retVal[2];
    for (i=0;i<2;i++)
    {
        err = pthread_create(&(tid[i]), NULL, worker, NULL);
        if (err != 0)
            printf("can't created\n");
        else
            printf("thread number:%d has been created\n",i+1);
    }
  	pthread_join(tid[0], (void**)&(retVal[0])); //pthread_join() beklenecek thread ID'sini alir ve ilgili thradin donus degerine ulasmayi saglar
    pthread_join(tid[1], (void**)&(retVal[1]));
    printf("\n return value from first thread is %d\n", *retVal[0]);
    printf("\n return value from second thread is %d\n",*retVal[1]);
 	return 0;
}




