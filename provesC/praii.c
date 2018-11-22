#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

void sigUsr(int sig);

int global = 0;
main()
{
    int x;
    pid_t pids[5];
    char msg[100];
    signal(SIGUSR1, sigUsr);
    for(x=0; x < 5; x++)
    {
        pids [x] = fork();
        if (pids[x]<0) perror("Error in fork\n");

        if (pids[x] == 0)
        {
            sprintf(msg, "%d\n",x+1);
            if(global==0){
                pause();
            }
            write(1,msg,strlen(msg));
            exit(0);
        }
    }
    for (x=0; x<5; x++) 
    {
        kill(pids[(2*x)%5], SIGUSR1);
        wait(NULL);    
    }
    return 0;
}

void sigUsr(int sig) {
    global++;
}
