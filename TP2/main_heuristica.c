#include <stdio.h>
#include <stdlib.h>
#include "heuristica.h"
#include <time.h>

int main() {
  int i;
  int N, M, wgt, srcId, destId;
  int maxDemand;
  int count = 0;
  int *possibleVert;
  int *selectedVert;
    
  if(scanf("%d", &N) >= 0) {};
  if(scanf("%d", &M) >= 0) {};
  Graph* City;
  City = newGraph(N);

  // vértices possíveis e já escolhidos para usar na heurística
  possibleVert = (int*)malloc(N*sizeof(int));
  selectedVert = (int*)malloc(N*sizeof(int));

  for(i=0; i<N; i++) {
    possibleVert[i] = 1;
    selectedVert[i] = 0;
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
  
  maxDemand = approximateVertices(City, possibleVert, selectedVert, N);
    
  for(i=0; i<N; i++) {
    if(selectedVert[i]) {
      count++;
    }
  }
  printf("%d %d\n", count, maxDemand);
  for(i=0; i<N; i++) {
		if(selectedVert[i]) {
			printf("%d ", i+1);
		}
	}
  printf("\n");

  deleteGraph(City);
  free(possibleVert);
  free(selectedVert);
  return 0;
}
