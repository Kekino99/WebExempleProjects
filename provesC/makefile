#compiler
CC=gcc
CFLAGS=

TARGETS= app10sec bas ex2 praii provaExec

all: $(TARGETS)
	
loteria: loteria.c
	$(CC) $(CFLAGS) -o $@ $^
	
generador: generador.c
	$(CC) $(CFLAGS) -o $@ $^

praii: praii.c
	$gcc -pedantic -ansi  -Wall -o pracii praii.c
ex2: ex2.c
	$gcc -pedantic -ansi  -Wall -o ex2 ex2.c
provaExec: provaExec.c
	$gcc -pedantic -ansi  -Wall -o provaExec provaExec.c


clean:
	rm -f *.o $(TARGETS)
