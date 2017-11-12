#ifndef _H_GRAFO
#define _H_GRAFO

typedef struct Adj {
  int id;
  struct Adj* next;
}Adj;

typedef struct Vertex { 
  int id;
  int weight;
  Adj* first;
}Vertex;

Vertex* newGraph(int V);

#endif