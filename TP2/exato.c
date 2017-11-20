#include <stdio.h>
#include <stdlib.h>
#include "exato.h"


// possibleVert é uma máscara de bits que será marcado com os ids 
// dos vértices possíveis de serem escolhidos
int findVertices(Graph* grafo, int possibleVert, int V) {
  int i;
  int nextVert;
  int next;
  int grau;

  // Caso base: se nenhum vértice pode 
  // fazer parte do CI, retorna 0
  if(possibleVert == 0) {
    return 0;
  }

  for(i=0; i<V; i++) {
    if((1<<i)&possibleVert) {
      break;
    }
  }
  nextVert = i;
  grau = 0;
  next = possibleVert - (1<<i);

  Adj* neighVert = grafo->array[nextVert].first;
  while(neighVert) {
    if(((1<<(neighVert->id-1))&next)) {
      next -= (1<<(neighVert->id-1));
      grau++;
    }
    neighVert = neighVert->next;
  }
  
  // abaixo, os condicionais verificam se o grau de um vértice atual
  // é 0, e se for, esse vértice é necessariamente parte da solução.
  // essa poda realizada reduz a complexidade (a ordem exponencial é menor).
  int vertInRes = findVertices(grafo, next, V) + grafo->array[nextVert].weight;
  if(grau == 0) {
    return vertInRes;
  }

  int vertNotInRes = findVertices(grafo, possibleVert - (1<<nextVert), V);
  if(vertNotInRes >= vertInRes) {
    return vertNotInRes;
  }
  return vertInRes;

}

// Método para recuperar a solução correta. Para todas as soluções
// na árvore de recursão que zerarem a demanda, temos como sendo uma 
// solução ótima.
void recoverResult(Graph* grafo, int possibleVert, int *solution, int demand, int aux, int V) {
  int i;
  int nextVert;
  int next;
  int grau;

  if(demand == 0) {
    if(__builtin_popcount(aux) > __builtin_popcount(*solution)) {
      *solution = aux;
    }
  }

  if(possibleVert == 0) {
    return;
  }
  
  for(i=0; i<V; i++) {
    if((1<<i)&possibleVert) {
      break;
    }
  }

  nextVert = i;
  grau = 0;
  next = possibleVert - (1<<i);

  Adj* neighVert = grafo->array[nextVert].first;

  while(neighVert) {
    if(((1<<(neighVert->id-1))&next)) {
      next -= (1<<(neighVert->id-1));
      grau++;
    }
    neighVert = neighVert->next;
  }

  recoverResult(grafo, next, solution, demand-grafo->array[nextVert].weight, aux|(1<<nextVert), V);
  // poda na recupearção
  if(grau == 0) {
    return;
  }

  recoverResult(grafo, possibleVert - (1<<i), solution, demand, aux, V);
}
