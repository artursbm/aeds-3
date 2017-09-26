#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------- PA 5: PRODUÇÃO EM ECATERIMBURGO --------- //
//               Problema 2115 do URI                //
// --------------------------------------------------//
typedef struct {
  long int di;
  long int pi;
} pedido;
pedido order[100010];

// O(nlog(n))
void merge(pedido tarefa[], int start, int middle, int end) {
  int s = start;
  int m = middle + 1;
  int l = 0;
  pedido Aux[end - start + 1];

  while (s <= middle && m <= end) {
    if (tarefa[s].di <= tarefa[m].di) {
      Aux[l] = tarefa[s];
      s++;
    }
    else {
      Aux[l] = tarefa[m];
      m++;
    }
    l++;
  }

  while (s <= middle) {
    // movendo elementos da primeira metade
    Aux[l] = tarefa[s];
    l++;
    s++;
  }

  while (m <= end) { 
    // movendo elementos da segunda metade
    Aux[l] = tarefa[m];
    l++;
    m++;
  }

  for (l = start; l <= end; l++) {
    // voltando os elementos ordenados para o vetor de tarefas
    tarefa[l] = Aux[l - start];
  }
}

void mergeSort(pedido tarefa[], int start, int end){
  if (start < end) {
    int middle = (end + start) / 2;

    mergeSort(tarefa, start, middle);
    mergeSort(tarefa, middle + 1, end);
    merge(tarefa, start, middle, end);
  }
}

int main() {
  long int N, i;
  // começo do programa
  while (scanf("%ld", &N) != EOF) {
    long int instante = 1;
    for (i = 0; i < N; i++) {
      scanf("%ld", &order[i].di);
      scanf("%ld", &order[i].pi);
    }
    // ordenando para as tarefas serem executadas
    // tão cedo elas cheguem
    mergeSort(order, 0, N-1);

    

    for(i=0; i<N; i++) {
      if(instante < order[i].di) {
        instante++;
        i--;
      }
      else {
        instante+=order[i].pi;
      }
    }
    printf("%ld", instante);
    printf("\n");
  }

  return 0;
}
