#include <stdlib.h>
#include <stdio.h>
#include "heuristica.h"

int selectBiggestVert(int i, Graph* grafo, int *possibleVert) {
  int auxWgt = grafo->array[i].weight;
  Adj* neighX = grafo->array[i].first;
  while(neighX) {
    if(possibleVert[neighX->id-1]) {
      if(auxWgt < grafo->array[neighX->id].weight) {
        auxWgt = grafo->array[neighX->id].weight;
        i = neighX->id-1;
      }
    }
    neighX = neighX->next;
  }
  return i;
}

void popVert(int *possibleVert, Graph* grafo, int x){
  possibleVert[x] = 0;
  Adj* neighX = grafo->array[x].first;
  while(neighX) {
    possibleVert[neighX->id-1] = 0;
    neighX = neighX->next;
  }
}

int approximateVertices(Graph* grafo, int *possibleVert, int *selectedVert, int V) {
  int i;
  int maxWeight = 0;
  
  for(i=0; i<V; i++) {
    if(possibleVert[i]){
      int x = selectBiggestVert(i, grafo, possibleVert);
      popVert(possibleVert,grafo, x);
      maxWeight += grafo->array[x].weight;
      selectedVert[x] = 1;
    }
  }
  return maxWeight;
}
