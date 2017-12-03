#ifndef _H_MATRIZ
#define _H_MATRIZ

int** createMatrix(int N);

void deleteMatrix(int** matriz, int N);

int** algoritmo1(int** A, int** B, int N);

int** algoritmo2(int** A, int** B, int N, int bsize);

void printResult(int** C, int N);

#endif