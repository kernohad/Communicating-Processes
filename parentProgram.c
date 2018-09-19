#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h>

void sigHandler1 (int);
void sigHandler2 (int); 

pid_t pid;


/*********************************************************
 * A program to learn about interprocess communication.
 * The parent process waits for signals sent by the child.
 *
 * Dustin Thurston & Dylan Kernohan
 *********************************************************/
int main() 
{	
	printf("Hello World!\n"); 

    signal (SIGUSR1, sigHandler1);
    signal (SIGUSR2, sighandler2);
    
    //fork the child process
    if((pid = fork()) < 0){
        perror("fork failed");
        exit(1);

    }else if(pid == 0){
        
        //get random amount of time
        int waitTime = rand() % 5 + 1;

        sleep(waitTime);


    }else{
        printf("spawned child PID: %d\n", pid);

    }


    printf ("waiting...\n");
    pause();
    return 0; 
}


void sigHandler1 (int sigNum){
        printf("received a SIGUSR1 signal.\n");
}

void sigHandler2 (int sigNum){

        printf("received a SIGUSR2 signal.\n");

}
