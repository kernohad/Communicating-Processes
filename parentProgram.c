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

    signal (SIGUSR1, sigHandler1);
    signal (SIGUSR2, sighandler2);

    printf ("waiting...\n");
    pause();
    return 0; 
}


void sigHandler1 (int sigNum){

    printf(" received an interrupt.\n");

    // This is where shutdown code would be insrted
    
    sleep(1);
    printf("outta here.\n");
    exit(0);
}

void sigHandler2 (int sigNum){

    printf(" received an interrupt.\n");

    // This is where shutdown code would be insrted
    
    sleep(1);
    printf("outta here.\n");
    exit(0);
}
