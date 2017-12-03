#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main() {
  int i, j;
  int N, bsize;
  int **A, **B, **C1;

  if(scanf("%d", &N) >= 0) {};
  if(scanf("%d", &bsize) >= 0) {};
  // condições de restrição de parada: 1<=N<=2000 || N%bsize != 0
  if(N<1 || N>2000 || N%bsize != 0 || bsize >50 || bsize < 1) {
    return 0;
  }

  A = createMatrix(N);
  B = createMatrix(N);

  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      if(scanf("%d", &A[i][j]) >= 0) {};
    }
  }

  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      if(scanf("%d", &B[i][j]) >= 0) {};
    }
  }

  C1 = algoritmo1(A, B, N);
  
  deleteMatrix(A, N);
  deleteMatrix(B, N);
  deleteMatrix(C1, N);

  return 0;
}