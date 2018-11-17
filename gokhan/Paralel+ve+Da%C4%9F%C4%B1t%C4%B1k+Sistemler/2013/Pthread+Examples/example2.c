#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *produce(void *);
void *consume(void *);

int tmp[5];
int main(int argc, char* argv[]){

     pthread_t thread1;
     pthread_t thread2;
     int i, j;
     int *k;
       
     for (j=0; j<5; j++) {
       if ((i=pthread_create(&thread1, NULL, produce, (void*)&j)) != 0) {
	 printf("thread creation failed. %d\n", j);
       }
     }

     pthread_join(thread1, NULL);

     printf("Exiting main\n");
     return 0;

}

void *produce(void *arg){
  int i;
  int me;
  me = *(int *)arg;
  for(i=0;i<1;i++){
    printf("I am %d, I produce item %d\n", me, i);
    sleep(1);
  }
  return NULL;
}

