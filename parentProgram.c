#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h>

void sigHandler (int);

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

    kill(0, SIGUSR1);

    printf ("waiting...\n");
    pause();
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

