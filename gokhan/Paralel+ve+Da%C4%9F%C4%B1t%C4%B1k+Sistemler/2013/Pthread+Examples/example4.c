#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int total_produced = 0;

void *produce(void *);
void *consume(void *);

int tmp[5];
int main(int argc, char* argv[]){

     pthread_t thread1[5];
     pthread_t thread2;
     int i, j;

     for (j=0; j<5; j++) {
       tmp[j] = j;
       if ((i=pthread_create(&thread1[j], NULL, produce, (void*)&tmp[j])) != 0) {
	 printf("thread creation failed. %d\n", j);
       }
     }

     if ((i=pthread_create(&thread2, NULL, consume, (void*)NULL)) != 0) {
       printf("thread creation failed. %d\n", i);
     }

     pthread_join(thread1[0], NULL);
     pthread_join(thread1[1], NULL);
     pthread_join(thread1[2], NULL);
     pthread_join(thread1[3], NULL);
     pthread_join(thread1[4], NULL);
     pthread_join(thread2, NULL);

     printf("Exiting main, total number of products %d\n", total_produced);
     return 0;

}

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void *produce(void *arg){
  int i;
  int me;

  me = *(int *)arg;
  for(i=0;i<1000000;i++){
    total_produced++;
  }
  return NULL;
}

void *consume(void *arg){
  int i;
  for(i=0;i<10;i++){
  }
  return NULL;
}


