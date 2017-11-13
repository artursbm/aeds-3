#include <stdio.h>
#include <stdlib.h>
#include "exato.h"

int findMaxDemand(Graph* graph) {
  Set* setMax = (Set*)malloc((graph->array.V+1)sizeof(Set*));
  if(graph->V == 0) {
    maxDemand[graph->V].id = graph->array[0].id;
    maxDemand[graph->V].weight = graph->array[V].weight;;
  }
  if(graph->V == 1) {

    maxDemand[graph->V] = graph->array[V].weight;
  }


}

