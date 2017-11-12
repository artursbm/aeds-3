#ifndef _H_GRAFO
#define _H_GRAFO

typedef struct Adj {
  int id;
  struct Adj *next;
}Adj;

typedef struct Vertex {
  int id;
  int weight;
  Adj *first; // pointer to first node of list
}Vertex;

typedef struct Graph {
  int V;
  Vertex *array;
}Graph;

Adj* newAdjNode(int dest);
 
Graph* newGraph(int V);

void addWeight(Graph* graph, int w, int id);
 
void addEdge(Graph* graph, int src, int dest);
 
void printGraph(Graph* graph);

// typedef struct Adj {
//   int id;
//   struct Adj* next;
// }Adj;

// typedef struct Vertex {
//   int id;
//   int weight;
//   Adj* first;
// }Vertex;

//Vertex *newGraph(int V);

#endif