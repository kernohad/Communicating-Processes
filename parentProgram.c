#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h>
#include <time.h>

/*********************************************************
 * A program to learn about interprocess communication.
 * The parent process waits for signals sent by the child.
 *
 * Dustin Thurston & Dylan Kernohan
 *********************************************************/

void sigHandler (int);

pid_t pid;
pid_t parentPID;


int main() 
{
    srand(time(0));
    parentPID = getppid();
    signal (SIGUSR1, sigHandler);
    signal (SIGUSR2, sigHandler);

    //fork the child process
    if((pid = fork()) < 0){
        perror("fork failed");
        exit(1);

    }else if(pid == 0){
        
        while(1){        
            //get random amount of time
            int waitTime = rand() % 5 + 1;
            sleep(waitTime);
            
            //get random signal to send
            int randSig = rand() % 2 + 1;

            if(randSig == 1){
            
                kill(getppid(), SIGUSR1);
            
            }else if (randSig == 2){
                
                kill(getppid(), SIGUSR2);
            
            }
        }
    }else{
        
        // override ctrl-C signal in parent branch so only the parent knows about the override
        signal (SIGINT, sigHandler);
        printf("spawned child PID: %d\n", pid);

        while(1){
            printf ("waiting...     ");
            fflush(stdout);
            pause();
        }

    
    }

   return 0; 
}


void sigHandler (int sigNum){

    if(sigNum == SIGUSR1){
        printf("received a SIGUSR1 signal\n");
        return;
    }
    else if(sigNum == SIGUSR2){
        printf("received a SIGUSR2 signal\n");
        return;
    }
    else if(sigNum == SIGINT){
        printf(" received. That's it, I'm shutting you down...\n");
    }

    //Handling the interrupt to shut down the code    
    exit(0);
}

