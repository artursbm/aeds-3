CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: block alg1
alg1: matriz.o main1.o
	gcc matriz.o main1.o -o alg1
block: matriz.o main.o
	gcc matriz.o main.o -o block
main1.o: main1.c matriz.h
	gcc $(CFLAGS) main1.c
main.o: main.c matriz.h
	gcc $(CFLAGS) main.c
matriz.o: matriz.c matriz.h
	gcc $(CFLAGS) matriz.c

clean:
	rm block alg1
	rm *.o *.gch