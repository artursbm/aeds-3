#include <stdio.h>
#include <stdlib.h>
#include "exato.h"

int main() {
  int i;
  int N, M, wgt, srcId, destId;
  int maxDemand;
  int vertices = 0;
  
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

	maxDemand = findVertices(City, (1<<N)-1, N);
	recoverResult(City, (1<<N)-1, &vertices, maxDemand, 0, N);

	printf("%d %d\n", (int)__builtin_popcount(vertices), maxDemand);
	for(i=0; i<N; i++) {
		if((1<<i)&vertices) {
			printf("%d ", i+1);
		}
	}
  printf("\n");
  
  deleteGraph(City);

  return 0;
}