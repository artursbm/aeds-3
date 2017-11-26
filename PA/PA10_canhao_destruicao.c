#include <stdio.h>
#include <stdlib.h>

// ------- PA 10: Canhão de Destruição --------- //
//               Problema 1288 do URI                //
// --------------------------------------------------// 

int max(int a, int b) {
  if(a>=b) 
    return a;
  else
    return b;
}

int tabela[51][101];
int peso[51];
int poder[51];

int main() {
  int i, j, w;
  // 1 <= N <= 50 projeteis disponiveis
  int T, N;
  int R;
  int K;
  scanf("%d", &T);

  for(i=0; i<T; i++) {
    scanf("%d", &N); // número de projeteis

    for(j=1; j<=N; j++) {
      scanf("%d", &poder[j]);
      scanf("%d", &peso[j]);
    }
      scanf("%d", &K); // capacidade do canhão
      scanf("%d", &R); // resistencia do castelo
  
    for(j=0; j<N; j++) {
      tabela[j][0] = 0;
    }
    for(j=1; j<=101; j++) {
      tabela[0][j] = 0;
    }

    for(j=1; j<=N; j++) {
      for(w=1; w<=K; w++) {
        if (peso[j] > w) {
          tabela[j][w] = tabela[j-1][w];
        } else {
          tabela[j][w] = max(tabela[j-1][w], (tabela[j-1][w-peso[j]] + poder[j]));
        }
      }
    }

    int result = tabela[N][K];
    if(result >= R) {
      printf("Missao completada com sucesso\n");
    } else {
      printf("Falha na missao\n");
    }
  
  }
  return 0;
}