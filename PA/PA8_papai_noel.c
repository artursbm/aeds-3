#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// a structure to represent a weighted edge in graph
struct Aresta {
    int src;
    int dest;
    int weight;
};
 
// grafo com V vértices e A arestas
// será uma lista de adjacência
struct Grafo {
    int V;
    int A;
    struct Aresta* aresta;
};

// subconjunto que representa a união para a geração da MST
struct Subset {
    int pai;
    int pos;
};
 
// alocação de memória para a lista de adjacência
struct Grafo* newGraph(int V, int A) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->V = V;
    grafo->A = A;
 
    grafo->aresta = (struct Aresta*)malloc(A*sizeof(struct Aresta));
 
    return grafo;
}
  
// encontra o subconjunto do elemento e da árvore
int Encontra(struct Subset subset[], int e) {
    // encontra a raiz da árvore e a faz pai de e
    if (subset[e].pai != e)
        subset[e].pai = Encontra(subset, subset[e].pai);
 
    return subset[e].pai;
}
 
// faz a junção de dois subconjuntos x e y
void Junta(struct Subset subset[], int x, int y) {
    int xroot = Encontra(subset, x);
    int yroot = Encontra(subset, y);
 
    // adiciona a menor subárvore (menor pelo peso)
    // na maior árvore gerada
    if (subset[xroot].pos < subset[yroot].pos) {
        subset[xroot].pai = yroot;
    } else if (subset[xroot].pos > subset[yroot].pos) {
        subset[yroot].pai = xroot;
    } else {
        subset[yroot].pai = xroot;
        subset[xroot].pos++;
    }
    // se posições iguais (por causa de peso igual), 
    // escolhe um arbitrariamente e incrementa seu pos 
}
 
// compara 2 pesos de duas arestas, função auxiliar
int Compara(const void* a, const void* b) {
    struct Aresta* a1 = (struct Aresta*) a;
    struct Aresta* b1 = (struct Aresta*) b;
  
    if(a1->weight > b1->weight) {
      return 1;
    } else {
      return 0;
    }
}
 
// função para encontrar árvore geradora mínima do grafo dado, 
// ou seja, encontra o menor itinerário entre as cidades do mapa
int FindMST(struct Grafo* grafo) {
  // variável que guarda o resultado dos pesos mínimos
  int resultado = 0; 
  int V = grafo->V;
  // conjunto de arestas que formam a árvore geradora mínima
  struct Aresta result[V]; 
  int j = 0;
  int a = 0; 
  int i = 0; 

  // ordenando todas as arestas com quicksort da stdlib
  qsort(grafo->aresta, grafo->A, sizeof(grafo->aresta[0]), Compara);

  // creando novo subset para alocar as árvores de 1 elemento
  struct Subset *subset = (struct Subset*) malloc( V * sizeof(struct Subset) );

  // identificando as árvores, ou os vértices do grafo
  for (j=0; j<V; j++) {
      subset[j].pai = j;
      subset[j].pos = 0;
  }

  // serão necessárias V-1 arestas para formar a árvore geradora mínima
  while (a < V - 1) {
    // encontra a aresta de menor peso e agrega ela
    //  à árvore geradora em construção
    struct Aresta prox_aresta = grafo->aresta[i++];
    int x = Encontra(subset, prox_aresta.src);
    int y = Encontra(subset, prox_aresta.dest);

    // checa se não está ocorrendo um ciclo,
    // e inclui a árovre geradora mínima em construção
    // o índice resultado da próxima aresta
    if (x != y) {
        result[a++] = prox_aresta;
        Junta(subset, x, y);
    }
  }
  // retorna o peso da árvore geradora mínima
  int res = 0;
  for (i=0; i<a; ++i) {
      res += result[i].weight;
  }
  return res;
}
 
int main() {
  int i, j;
  int M, N, X, Y, Z;            
    
  // início dos casos de teste
  while (scanf("%d", &M) && M != 0 && scanf("%d", &N) && N != 0) {

    // cria um grafo não dirigido com M vértices e N arestas.
    struct Grafo* grafo = newGraph(M, N); 

    for(i=0; i<N; i++) {
      scanf("%d", &X);
      scanf("%d", &Y);
      scanf("%d", &Z);
      grafo->aresta[i].src = X;
      grafo->aresta[i].dest = Y;
      grafo->aresta[i].weight = Z;
    }

    int peso_min = FindMST(grafo);
    printf("%d", peso_min);
    printf("\n");
  } 
 
    return 0;
}