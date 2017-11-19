CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: exato
exato: main_exato.o exato.o grafo.o
	gcc main_exato.o exato.o grafo.o -o exato
main_exato.o: main_exato.c exato.h
	gcc $(CFLAGS) main_exato.c
grafo.o: grafo.h grafo.c
	gcc $(CFLAGS) grafo.c
exato.o: exato.h exato.c
	gcc $(CFLAGS) exato.c
# all: heuristica
# heuristica: heuristica.o grafo.o
# 	gcc heuristica.o grafo.o -o heuristica
# heuristica.o: heuristica.c grafo.h
# 	gcc $(CFLAGS) heuristica.c
clean:
	rm *.o *.gch
	