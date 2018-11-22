#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
int main()
{
    char buf[256];
	int pid;
	int fp1[2];

	while(TRUE)
	{
		read(0, buf, sizeof(buf));
		if (pipe(fp1)== -1) { 
		    perror("Creación Pipe:"); 
		    exit(-1); 
		} 
		if((pid = fork()) == 0){
			/*Canviar stdout*/
		    close(1);
		    dup(fp1[1]);
		    close(fp1[1]);
		    /*Tancar fitxers innecessaris*/
		    close(fp1[0]);
		    
			execlp("ps", "ps", "-aux", NULL); /*executar la funció ps -aux */
			perror("Fallat execl Fill1");			
			exit(-1);
		}
		else{
			if((pid = fork()) == 0){
		   		/*Canviar stdin*/
		        close(0);
		        dup(fp1[0]);
		        close(fp1[0]);
		        /*Tancar fitxers innecessaris*/
		        close(fp1[1]);
			    execlp("grep", "grep", "-c", "S", NULL); /*executar la funció grep -c S*/
				perror("Fallat execl Fill2");
			    exit(-1);
		    }
		    else{
		        close(fp1[0]);
		        close(fp1[1]);
		        wait(NULL);
				wait(NULL);
		    }
		}
	}
	exit(0);
}

