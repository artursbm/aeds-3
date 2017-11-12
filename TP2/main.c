#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
  // número de esquinas (N vértices) e ruas da cidade (M arestas)
  int N, M;
  // variáveis de controle
  int i;
  int wgt; //, srcId, destId;

  if(scanf("%d", &N) >= 0) {};
  if(scanf("%d", &M) >= 0) {};
  Vertex* City = newGraph(N);
  
  for(i=1; i<=N; i++) {
    if(scanf("%d", &wgt) >= 0) {};
    City[i].id = i;
    City[i].weight = wgt;
  }


  return 0;
}