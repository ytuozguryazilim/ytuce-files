
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *produce(void *);
void *consume(void *);


int main(int argc, char* argv[]){

     pthread_t thread1;
     pthread_t thread2;
     int i;
     if ((i=pthread_create(&thread1, NULL, produce, (void*)NULL)) != 0) {
       printf("thread creation failed. %d\n", i);
     }

     if ((i=pthread_create(&thread2, NULL, consume, (void*)NULL)) != 0) {
       printf("thread creation failed. %d\n", i);
     }

     pthread_join(thread1, NULL);
     pthread_join(thread2, NULL);

     printf("Exiting main\n");
     return 0;

}

void *produce(void *arg){
  int i;
  for(i=0;i<10;i++){
    printf("I produce\n");
    sleep(1);
  }
  return NULL;
}

void *consume(void *arg){
  int i;
  for(i=0;i<10;i++){
    printf("I consume\n");
    sleep(1);
  }
  return NULL;
}


