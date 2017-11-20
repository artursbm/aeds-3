#ifndef _H_HEURISTICA
#define _H_HEURISTICA

#include "grafo.h"

int pego_melhor(int i, Graph* grafo, int *pode_ta);
void tira_lixo(int *pode_ta, Graph* grafo, int x);
int approximateVertices(Graph* grafo, int *pode_ta, int *jata, int V);


#endif