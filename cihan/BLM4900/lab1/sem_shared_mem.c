/*
 *  sem_shared_mem.c
 *
 *  multiple processes accessing a share memory and
 *  using a named semaphotre for syncing
 *
 *  Created by Z. Cihan TAYSI on 02/03/18.
 *  Original source file available at http://www.ce.yildiz.edu.tr/personal/cihan/
 *
 */

#include <stdio.h>
#include <sys/types.h>  // for shm_* and mmap()
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>     // for getpid()
#include <stdlib.h>     // for exit()
#include <sys/stat.h>   // for sem_* functions
#include <semaphore.h>
#include <time.h>       // for seeding time()

#define     SEM_NAME            "/semshm"
#define     SHM_PATH            "/shm_cnt01"
#define     MAX_SLEEP_SECS      3
#define     MAX_INC_VALUE       10

#define     RC_SEM_FAILED  -1
#define     RC_SHM_FAILED  -2
#define     RC_FRK_FAILED  -3

int main(int argc, char *argv[]) {
    int shmfd;
    int sh_seg_size = sizeof(int);
    int *sh_val;     // reference to shared element
    sem_t *sem_shm;  // semaphore controlling access to the shared segment
    pid_t mypid;
    
    
    // creating a new semaphore for the shared segment
    sem_shm = sem_open(SEM_NAME, O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, 1);
    if ((int)sem_shm == SEM_FAILED) {
        perror("In sem_open() : ");
        exit(RC_SEM_FAILED);
    }

    // requesting the semaphore not to be held when completely unreferenced
    sem_unlink(SEM_NAME);
    
    shmfd = shm_open(SHM_PATH, O_CREAT | O_EXCL | O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0) {
        perror("In shm_open() : ");
        exit(RC_SHM_FAILED);
    }
    ftruncate(shmfd, sh_seg_size);
    
    // requesting the shared segment
    sh_val = (int *)mmap(NULL, sh_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (sh_val == NULL) {
        perror("In mmap() : ");
        exit(RC_SHM_FAILED);
    }
    fprintf(stderr, "Shared memory segment allocated correctly (%d bytes) at %x.\n", sh_seg_size, sh_val);

    shm_unlink(SHM_PATH);
    
    if (! fork() )
        // send the child to bed for a 2-sec sleep...
        sleep(2);
    
    // seeding the random number generator
    srandom(time(NULL));
    
    // getting your pid, and introducing yourself
    mypid = getpid();
    printf("My pid is %d\n", mypid);
    
    /*
     main loop:
     - pause
     - print the old value
     - choose a random quantity
     - increment the segment by that
     */
    do {
        sleep(random() % (MAX_SLEEP_SECS+1));       // pausing for at most MAX_SLEEP_SECS seconds
        
        sem_wait(sem_shm); // entering critical section
        
        //printf("Hello\n");
        printf("process %d. Former value %d.", mypid, *sh_val);
        
        *sh_val += random() % (MAX_INC_VALUE+1);            /* choose a random value up to MAX_INC_VALUE */
        
        printf(" new value %d.\n", *sh_val);
        
        sem_post(sem_shm); // leaving critical section
    } while (1);
    
    sem_close(sem_shm);
    
    return 0;
}
