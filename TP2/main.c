#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
  // número de esquinas (N vértices) e ruas da cidade (M arestas)
  int N, M;
  // variáveis de controle
  int i;
  int wgt, srcId, destId;

  if(scanf("%d", &N) >= 0) {};
  if(scanf("%d", &M) >= 0) {};
  Graph* City;
  City = newGraph(N);
  
  for(i=1; i<=N; i++) {
    if(scanf("%d", &wgt) >= 0) {};
    addWeight(City, wgt, i);
  }

  for(i=1; i<=M; i++) {
    if(scanf("%d", &srcId) >= 0) {};
    if(scanf("%d", &destId) >= 0) {};
    addEdge(City, srcId, destId);
  }


  printGraph(City);


  return 0;
}