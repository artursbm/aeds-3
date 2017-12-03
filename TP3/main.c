#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main() {
  int i, j;
  int N, bsize;
  int **A, **B, **C1, **C2;

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
  C2 = algoritmo2(A, B, N, bsize);

  // PROCEDIMENTO PARA CÁLCULO DE TEMPO DE EXECUÇÃO
  // double time_spent_alg1 = 0;
  // double time_spent_alg2 = 0;

  // for(i=0; i<30; i++) {
  //   clock_t alg1_start = clock();
  //     C1 = algoritmo1(A, B, N);
  //   clock_t alg1_end = clock();
  //   time_spent_alg1 += (double)(alg1_end - alg1_start) / CLOCKS_PER_SEC;
    
  //   clock_t alg2_start = clock();
  //     C2 = algoritmo2(A, B, N, bsize);
  //   clock_t alg2_end = clock();
  //   time_spent_alg2 += (double)(alg2_end - alg2_start) / CLOCKS_PER_SEC;
  // }

  // double total1 = time_spent_alg1/30;
  // double total2 = time_spent_alg2/30;

  // FILE * pFile;
  // pFile = fopen ("testes_result.txt","a+");
  // if (pFile!=NULL)
  // {
  //   fprintf(pFile,"======= inicio da medição de N=%d, bsize=%d ========\n",N, bsize);
  //   fprintf(pFile,"tempo do algoritmo 1 = %lf s\n", total1);
  //   fprintf(pFile,"tempo do algoritmo 2 = %lf s\n", total2);
  //   fprintf(pFile,"======= fim da medição de N=%d, bsize=%d ========\n\n",N, bsize);
  //   fclose (pFile);
  // }
  
  // Resultados da multiplicação em cada algoritmo
  printResult(C2, N);
  printf("\n");

  deleteMatrix(A, N);
  deleteMatrix(B, N);
  deleteMatrix(C1, N);
  deleteMatrix(C2, N);

  return 0;
}