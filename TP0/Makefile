CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: arvore matriz
arvore: arvore.o main_arvore.o dados.o
	gcc arvore.o main_arvore.o dados.o -o arvore 
main_arvore.o: main_arvore.c arvore.h dados.h
	gcc $(CFLAGS) main_arvore.c
arvore.o: arvore.h arvore.c dados.o
	gcc $(CFLAGS) arvore.c
matriz: matriz.o main_matriz.o dados.o
	gcc matriz.o main_matriz.o dados.o -o matriz
main_matriz.o: main_matriz.c matriz.h dados.h
	gcc $(CFLAGS) main_matriz.c
matriz.o: matriz.h matriz.c dados.o
	gcc $(CFLAGS) matriz.c
dados.o: dados.h dados.c
	gcc $(CFLAGS) dados.c
clean:
	rm *.o *.gch
	rm matriz