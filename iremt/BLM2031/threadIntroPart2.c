#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_t tid[2];
//worker fonksiyon 
void* worker(void *arg)
{
	pthread_t id = pthread_self();  // aktif thread'in ID'sini dondurur
    if(pthread_equal(id,tid[0]))	// aktif thread'in kacinci thread oldugu kontrol edilir
    	printf("I am first tread\n");
	else
    	printf("I am second tread\n");
}
int main(void)
{
    int i = 0, err;
    for (i=0;i<2;i++)
    {
        err = pthread_create(&(tid[i]), NULL, worker, NULL); //Id'leri tid[]'de tutulan iki thread varsayilan ozellikler ile olusturulur
        if (err != 0)
            printf("can't created\n");
        else
            printf("thread number:%d has been created\n",i+1);
    }
  	sleep(5); //threadler sonlanana kadar ana fonksiyonu bekletir
 	return 0;
}




