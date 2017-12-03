#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int** createMatrix(int N) {
  int** m;
  int i=0;
  m = malloc(N * sizeof(int*));
  for(i=0; i<N; i++) {
      m[i] = malloc(N * sizeof(int));
  }
    return m;
}

void deleteMatrix(int** matriz, int N) {
  int i=0;
  for(i=0; i<N; i++) {
      free(matriz[i]);
  }
  free(matriz);
}

int** algoritmo1(int** A, int** B, int N) {
  int i, j, k;
  int** C;
  C = createMatrix(N);
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      C[i][j] = 0;
      for(k=0; k<N; k++) {
        C[i][j] += (A[i][k] * B[k][j]);
      }
    }
  }

    return C;

}

int** algoritmo2(int** A, int** B, int N, int bsize) {
  int i, j, k, jj, kk;
  int sum=0;
  int** C;
  C = createMatrix(N);

  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      C[i][j] = 0;
    }
  }
  
  for(kk=0; kk<N; kk+=bsize) {
    for(jj=0; jj<N; jj+=bsize) {
      for(i=0; i<N; i++) {
        for(j=jj; j<(jj+bsize); j++) {
          sum = C[i][j];
          for(k=kk; k<(kk+bsize); k++) {     
            sum += A[i][k] * B[k][j];
          }
          C[i][j] = sum;
        }
      }
    }
  }

    return C;
}

void printResult(int** C, int N) {
  int i,j;
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
}