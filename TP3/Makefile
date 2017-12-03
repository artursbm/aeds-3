CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: block block_alg1 block_alg2
block_alg1: matriz.o main1.o
	gcc matriz.o main1.o -o block_alg1
main1.o: main1.c matriz.h
	gcc $(CFLAGS) main1.c
block_alg2: matriz.o main2.o
	gcc matriz.o main2.o -o block_alg2
main2.o: main2.c matriz.h
	gcc $(CFLAGS) main2.c
block: matriz.o main.o
	gcc matriz.o main.o -o block
main.o: main.c matriz.h
	gcc $(CFLAGS) main.c
matriz.o: matriz.c matriz.h
	gcc $(CFLAGS) matriz.c

clean:
	rm block block_alg1 block_alg2
	rm *.o *.gch