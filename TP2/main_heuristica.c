#include <stdio.h>
#include <stdlib.h>
#include "heuristica.h"

int main() {
  int i;
  int N, M, wgt, srcId, destId;
  int maxDemand;
  int count = 0;
  int *ta;
  int *jata;
    
  if(scanf("%d", &N) >= 0) {};
  if(scanf("%d", &M) >= 0) {};
  Graph* City;
  City = newGraph(N);

  // vértices possíveis e já escolhidos para usar na heurística
  ta = (int*)malloc(N*sizeof(int));
  jata = (int*)malloc(N*sizeof(int));

  for(i=0; i<N; i++) {
    ta[i] = 1;
    jata[i] = 0;
  }
  
  for(i=0; i<N; i++) {
    if(scanf("%d", &wgt) >= 0) {};
    addWeight(City, wgt, i);
  }

  for(i=0; i<M; i++) {
    if(scanf("%d", &srcId) >= 0) {};
    if(scanf("%d", &destId) >= 0) {};
    addEdge(City, srcId, destId);
  }
  
  maxDemand = approximateVertices(City, ta, jata, N);
  for(i=0; i<N; i++) {
    if(jata[i]==1) {
      count++;
    }
  }
  printf("%d %d\n", maxDemand, count);
  for(i=0; i<N; i++) {
		if(jata[i]==1) {
			printf("%d ", i+1);
		}
	}
  printf("\n");

  deleteGraph(City);
  free(ta);
  free(jata);
  return 0;
}
