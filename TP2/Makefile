CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
# all: grafo exato
# # exato: exato.o grafo.o main.o -o exato
# grafo: grafo.o main.o
# 	gcc grafo.o main.o -o grafo
# main.o: main.c grafo.h
# 	gcc $(CFLAGS) main.c
# grafo.o: grafo.h grafo.c
# 	gcc $(CFLAGS) grafo.c
# # exato.o: exato.h exato.c
# 	# gcc $(CFLAGS) exato.c
all: heuristica
heuristica: heuristica.o grafo.o
	gcc heuristica.o grafo.o -o heuristica
heuristica.o: heuristica.c grafo.h
	gcc $(CFLAGS) heuristica.c
grafo.o: grafo.h grafo.c
	gcc $(CFLAGS) grafo.c

clean:
	rm grafo heuristica 
	rm *.o *.gch
	