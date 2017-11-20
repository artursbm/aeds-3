#include <stdlib.h>
#include <stdio.h>
#include "heuristica.h"

int pego_melhor(int i, Graph* grafo, int *pode_ta) {
  int auxWgt = grafo->array[i].weight;
  Adj* neighX = grafo->array[i].first;
  while(neighX) {
    if(pode_ta[neighX->id-1]) {
      if(auxWgt < grafo->array[neighX->id].weight) {
        auxWgt = grafo->array[neighX->id].weight;
        i = neighX->id;
      }
    }
    neighX = neighX->next;
  }
  return i;
}

void tira_lixo(int *pode_ta, Graph* grafo, int x){
  pode_ta[x] = 0;
  Adj* neighX = grafo->array[x].first;
  while(neighX) {
    pode_ta[neighX->id-1] = 0;
    neighX = neighX->next;
  }
}

int approximateVertices(Graph* grafo, int *pode_ta, int *jata, int V) {
  int i;
  // unsigned int id = 0;
  int maxWeight = 0;
  
  for(i=0; i<V; i++) {
    if(pode_ta[i]){
      int x = pego_melhor(i, grafo, pode_ta);
      tira_lixo(pode_ta,grafo, x);
      maxWeight += grafo->array[x].weight;
      jata[x] = 1;
    }
  }
  return maxWeight;
}
