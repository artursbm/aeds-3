#ifndef _H_EXATO
#define _H_EXATO

#include "grafo.h"

// produz todos os tipos de grafos possíveis dados V vértices
int** makeAllSets(int V);
// verifica se, dentro do conjunto de todos os grafos, 
// o grafo i é um conjunto independente de [grafo]
int isSetIndependent(Graph* grafo, int** allGraphs);

#endif