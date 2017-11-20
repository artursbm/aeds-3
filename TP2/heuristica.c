#include <stdlib.h>
#include <stdio.h>
#include "heuristica.h"


int approximateVertices(Graph* grafo, unsigned int* sol, int bitMask, int V) {
  int i;
  // unsigned int id = 0;
  int maxWeight = 0;
  int auxWeight = 0;
  // controla os vértices já analisados
  unsigned int popMask = (1<<V)-1;
  for(i=0; i<V; i++) {
    if((1<<i)&popMask) {
      // retiro i da mascara pois ja está sendo avaliado
      popMask -= (1<<i)&popMask;
      // boto o peso de i como o peso atual
      auxWeight = grafo->array[i].weight;
      
      // iterador sobre lista de adj de vértices de i
      Adj* checkNeigh = grafo->array[i].first;
      while(checkNeigh) {
        // se o vertice [id-1] estiver na mascara e seu peso for maior que o peso atual
        if((1<<(checkNeigh->id-1)&popMask) && grafo->array[checkNeigh->id-1].weight > auxWeight) {
          
          // peso atual é o peso de [id-1]
          auxWeight = grafo->array[checkNeigh->id-1].weight;
          // retiro o id verificado da lista de possibilidades
          popMask -= (1<<(checkNeigh->id-1))&popMask;
          
        } else {
          popMask -= (1<<(checkNeigh->id-1))&popMask;
          
        }
        checkNeigh = checkNeigh->next;
      } 
      maxWeight += auxWeight;
    }
  }
  *sol = bitMask;
  return maxWeight;

  // PRECISO CONSERTAR A MASCARA DE BITS, E FAZER O ALGORITMO VERIFICAR SE O VIZINHO JA FOI USADO
  // USAR POPCOUNT()????
}

int main() {
  int i;
  int N, M, wgt, srcId, destId;
  int maxDemand;
  //int vertices = 0;
  
  if(scanf("%d", &N) >= 0) {};
  if(scanf("%d", &M) >= 0) {};
  Graph* City;
  City = newGraph(N);

  for(i=0; i<N; i++) {
    if(scanf("%d", &wgt) >= 0) {};
    addWeight(City, wgt, i);
  }

  for(i=0; i<M; i++) {
    if(scanf("%d", &srcId) >= 0) {};
    if(scanf("%d", &destId) >= 0) {};
    addEdge(City, srcId, destId);
  }
//TODO: DELETAR 2 LINHAS ABAIXO
  printGraph(City);
  printf("\n\n");

  unsigned int vertices = 0;
  maxDemand = approximateVertices(City, &vertices, (1<<N)-1, N);
  printf("%d %u\n", maxDemand, (int)__builtin_popcount(vertices));
  for(i=0; i<N; i++) {
		if((1<<i)&vertices) {
			printf("%d ", i+1);
		}
	}
  printf("\n");

  deleteGraph(City);

  return 0;
}
