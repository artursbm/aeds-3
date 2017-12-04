#ifndef _H_MATRIZ
#define _H_MATRIZ

// aloca memória para uma matriz quadrada NxN
int** createMatrix(int N);
// libera memória alocada da matriz 
void deleteMatrix(int** matriz, int N);
// executa a multiplicação de matrizes C = AB pelo algoritmo 1
int** algoritmo1(int** A, int** B, int N);
// executa a multiplicação de matrizes C = AB pelo algoritmo 2
int** algoritmo2(int** A, int** B, int N, int bsize);
// imprime o resultado da multiplicação de matrizes AB
void printResult(int** C, int N);

#endif