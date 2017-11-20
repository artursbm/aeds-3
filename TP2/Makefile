CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: exato heuristica
heuristica: heuristica.o grafo.o
	gcc heuristica.o grafo.o -o heuristica
exato: main_exato.o exato.o grafo.o
	gcc main_exato.o exato.o grafo.o -o exato
main_exato.o: main_exato.c exato.h
	gcc $(CFLAGS) main_exato.c
heuristica.o: heuristica.c heuristica.h grafo.h 
	gcc $(CFLAGS) heuristica.c
grafo.o: grafo.h grafo.c
	gcc $(CFLAGS) grafo.c
exato.o: exato.h exato.c
	gcc $(CFLAGS) exato.c
clean:
	rm exato heuristica *.o *.gch