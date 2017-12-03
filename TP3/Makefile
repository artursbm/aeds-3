CFLAGS := -g -c -Wall -Wextra -Werror -std=c99 -pedantic -O2 
all: block
block: matriz.o main.o
	gcc matriz.o main.o -o block
matriz.o: matriz.c matriz.h
	gcc $(CFLAGS) matriz.c
main.o: main.c matriz.h
	gcc $(CFLAGS) main.c

clean:
	rm block
	rm *.o *.gch