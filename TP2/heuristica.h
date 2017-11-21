#ifndef _H_HEURISTICA
#define _H_HEURISTICA

#include "grafo.h"

int selectBiggestVert(int i, Graph* grafo, int *possibleVert);
void popVert(int *possibleVert, Graph* grafo, int x);
int approximateVertices(Graph* grafo, int *possibleVert, int *selectedVert, int V);


#endif