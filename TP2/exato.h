#ifndef _H_EXATO
#define _H_EXATO

#include "grafo.h"

int findVertices(Graph* grafo, int possibleVert, int V);
void recoverResult(Graph* grafo, int possibleVert, int *solution, int demand, int aux, int V);

#endif