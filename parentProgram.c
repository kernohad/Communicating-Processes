#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h>

void sigHandler (int);

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

    signal (SIGUSR1, sigHandler);
    signal (SIGUSR2, sigHandler);
    
    //fork the child process
    if((pid = fork()) < 0){
        perror("fork failed");
        exit(1);

    }else if(pid == 0){
        
        //get random amount of time
        int waitTime = rand() % 5 + 1;

        sleep(waitTime);

        kill(0, SIGUSR1);

    }else{
        printf("spawned child PID: %d\n", pid);

        printf ("waiting...\n");
        pause();
    
    }

   return 0; 
}


void sigHandler (int sigNum){

    if(sigNum == SIGUSR1){
        printf("This is the SIGUSR1 signal.\n");
    }
    else if(sigNum == SIGUSR2){
        printf("This is the SIGUSR2 signal.\n");
    }

    // This is where shutdown code would be insrted
    
    sleep(1);
    printf("outta here.\n");
    exit(0);
}

