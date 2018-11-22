#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<time.h>

#include<string.h> /* Testos */

void printSig(int sig);
int main() {
	printf("Pid del pare %d\n", getpid());
	signal(SIGINT, printSig);	
	printf("Envia la senyal\n");
	fork();
	sleep(10);
	wait(NULL);
	return 0;
}

void printSig(int sig) {
	printf("S'ha rebut la senyal al %d\n", getpid());
}
