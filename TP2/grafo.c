#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

// TODO: REVISAR TODOS OS CÓDIGOS E DELETAR COISAS DESNECESSÁRIAS

Adj* newAdjNode(int dest) {
  Adj *newNode = (Adj*)malloc(sizeof(Adj));
  newNode->id = dest;
  newNode->next = NULL;
  return newNode;
}

Graph* newGraph(int V) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->V = V;

  // Create an array of adjacency lists.  Size of array will be V
  graph->array = (Vertex*)malloc((V)*sizeof(Vertex));

  // Initialize each adjacency list as empty by making first as NULL
  int i;
  for (i=0; i<V; i++) {
    graph->array[i].first = NULL;
  }
    return graph;
}

void addWeight(Graph* graph, int w, int id) {
  graph->array[id].weight = w;
  graph->array[id].id = id+1;
}

void addEdge(Graph* graph, int src, int dest) {
  // Add an edge from src to dest.  A new node is added to the adjacency
  // list of src.  The node is added at the begining
  Adj *newNode = newAdjNode(dest);
  newNode->next = graph->array[src-1].first;
  graph->array[src-1].first = newNode;

  // Since graph is undirected, add an edge from dest to src also
  newNode = newAdjNode(src);
  newNode->next = graph->array[dest-1].first;
  graph->array[dest-1].first = newNode;
}

void printGraph(Graph* graph) {
  int v;
  for (v=0; v<graph->V; v++) {
    Adj *pCrawl = graph->array[v].first;
    printf("[%d / %d] ", v+1, graph->array[v].weight);

    while (pCrawl) {
      printf("-> [%d / %d]", pCrawl->id, graph->array[pCrawl->id-1].weight);
      pCrawl = pCrawl->next;
    }

    printf("\n");
  }
}

void deleteEdges(Adj* adj) {
  if(adj->next != NULL) {
    deleteEdges(adj->next);
  }
  free(adj);
}

void deleteGraph(Graph* graph) {
  int i;
  for(i=0; i<graph->V; i++)  {
    if(graph->array[i].first != NULL) {
      Adj* adj = graph->array[i].first;
      deleteEdges(adj);
    }
  }
  free(graph->array);
  free(graph);
}