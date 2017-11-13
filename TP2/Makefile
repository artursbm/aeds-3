CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: grafo exato
# exato: exato.o grafo.o main.o -o exato
grafo: grafo.o main.o
	gcc grafo.o main.o -o grafo
main.o: main.c grafo.h
	gcc $(CFLAGS) main.c
grafo.o: grafo.h grafo.c
	gcc $(CFLAGS) grafo.c
# exato.o: exato.h exato.c
	# gcc $(CFLAGS) exato.c
clean:
	rm *.o *.gch
	rm grafo