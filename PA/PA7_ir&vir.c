#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------- PA 7: IR E VIR --------- //
//               Problema 1128 do URI                //
// --------------------------------------------------//
/*  EXEMPLO DE LISTA DE ADJACÊNCIA
  [1]--->[2]->[4]->[/]
  [2]--->[4]->[/]
  [3]--->[1]->[4]->[/]
  [4]--->[1]->[/]
*/

typedef struct Gr {
  int key;
  struct Gr *next;
}G;

 G grafo[2000];

int main()
{
  // número de vértices (N) e arestas (M)
  int N, M;
  // interseções (V e W) e direcionamento do grafo (P), se único ou duplo
  int V, W, P;
  int i, j;
  // início dos casos de teste
  while (scanf("%d", &N) && N != 0 && scanf("%d", &M) && M != 0) {
    // leitura para grafo
    for (i=0; i<N; i++) {
      grafo[i].key = i+1;
      for (j=0; j<M; j++) {
        scanf("%d", &V);
        scanf("%d", &W);
        scanf("%d", &P);
        if(P == 1) {
          grafo[V]->next = &grafo[W]; 
        } else {
          grafo[V]->next = &grafo[W]; 
          grafo[W]->next = &grafo[V]; 
        }
      }
      printf("%d \n", i);
    }
  }

  return 0;
}