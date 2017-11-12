CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: grafo
grafo: grafo.o main.o
	gcc grafo.o main.o -o grafo
main.o: main.c grafo.h
	gcc $(CFLAGS) main.c
grafo.o: grafo.h grafo.c
	gcc $(CFLAGS) grafo.c
clean:
	rm *.o *.gch
	rm grafo