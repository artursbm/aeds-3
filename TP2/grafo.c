#include "grafo.h"
#include <stdlib.h>

Vertex* newGraph(int V) {
    Vertex* graph = (Vertex*)malloc((V+1)*sizeof(Vertex));

    return graph;
}
