#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<time.h>

#include<string.h> /* Testos */

void rutina_alarm (){ 
  char buffer[250]; 
  signal (SIGALRM, rutina_alarm); 
  sprintf (buffer, "Ha arribat l’alarma\n"); 
  write (1, buffer, strlen (buffer)); 
} 

int main() 
{ 
	int id; 
	int estat; 
	  char buffer[250]; 
	  signal (SIGALRM, rutina_alarm); 
	id = fork(); 
	switch (id) 
	{ 
	case 0: 
		      sprintf (buffer, "Procés fill creat\n"); 
		      write (1, buffer, strlen (buffer));  
		execlp("./app10sec","./app10sec", NULL); 
	case -1: 
		      sprintf (buffer, "Error del fork\n"); 
		      write (1, buffer, strlen (buffer)); 
		      exit(1); 
	default: 
		wait (&estat); 
		      sprintf (buffer, "Final de l’aplicació\n"); 
		      write (1, buffer, strlen (buffer)); 
	} 
	return 0;
} 
