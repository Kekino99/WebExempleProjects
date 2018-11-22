#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<time.h>

#include<string.h> /* Testos */

int main() 
{ 
	char buffer[256];
	alarm(1); 
	sprintf (buffer, "Esperant alarma\n"); 
	  write (1, buffer, strlen (buffer)); 
	pause(); 
	printf("WTF\n");
	sprintf (buffer, "Final del programa\n"); 
	  write (1, buffer, strlen (buffer)); 
	exit (0); 
} 
