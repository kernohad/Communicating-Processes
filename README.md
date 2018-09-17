# Communicating-Processes
GVSU CIS-452 Lab 3

## Lab Programming Assignment (Communicating Processes)
Interprocess communication of some sort occurs in most significant programming projects.  Asynchronous communication is an IPC technique often used in systems programming, where processes must be able to respond to a variety of possible inputs and events.  For example, a child process may need to communicate to its parent that some condition has occurred, or not.  Experiment with asynchronous IPC by writing the following program that demonstrates the use of signals for simple communication.


* write a parent program that:
  * installs signal handler(s) for the _user-defined_ signals (SIGUSR1/SIGUSR2)
  * spawns off a child process
  * when a user-defined signal is raised, it reports the type of signal sent
    *note: it may be necessary to reinstall your signal handler after a signal is received
  * terminates gracefully upon receiving a Control-C
* the child process should repeatedly:
  * wait a random amount of time (e.g. one to five seconds)
  * randomly send one of the two user-defined signals to its parent
  
The program that produced the sample output listed below begins by spawning a child process.  It then reports the identity of any signal that is sent to it at random times by its child.  Finally, the main program is terminated and shutdown gracefully via an interrupt (Control-C) sigHandler.

__Sample Output:__

``` bash
[eos12:~/cs452]$ a.out
spawned child PID# 19772
waiting...       received a SIGUSR2 signal
waiting...       received a SIGUSR1 signal
waiting...       received a SIGUSR2 signal
waiting...       received a SIGUSR2 signal
waiting...       received a SIGUSR1 signal
waiting...       received a SIGUSR2 signal
waiting...       received a SIGUSR1 signal
waiting...       received a SIGUSR1 signal
waiting...       received a SIGUSR1 signal
waiting...       received a SIGUSR1 signal
waiting...      ^C received.  That's it, I'm shutting you down...
[eos12:~/cs452]$
```


