/*
 *  fork.c
 *
 *  Creates any number of given process,
 *  number of processes is given as a command line argument.
 *
 *  Created by Z. Cihan TAYSI on 02/03/18.
 *  Original source file available at http://www.ce.yildiz.edu.tr/personal/cihan/
 *
 */

#include <stdio.h>
#include <unistd.h> // for getpid function
#include <stdlib.h> // for exit function

/*
 *
 * Process ID of the child process can be written by the child itself
 * or by the parent using the return code of the fork system call.
 *
 */

int main(int argc, char *argv[]) {

    int i,n;
    pid_t mypid;
    
    if(argc!=2)  {
        printf("Invalid number of arguments\n\n\tUsage : ./%s [# of processes]\n", argv[0]);
        return -1;
    }

    sscanf(argv[1], "%d", &n);
    for(i=0;i<n;i++)  {
        if(!fork())  {   // child
            mypid = getpid();
            printf("process id : %d\n", mypid);
            exit(0);
        }
        // parent process will go on...
    }
    
    
    return 0;
}
