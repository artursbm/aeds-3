#include <stdio.h>
#include <string.h>

// ------- PA 5: CABO DE GUERRA --------- //
//                                        //
// ---------------------------------------// 
long long int score[100000];
int getSize(char *Nome) {
  int i, sum = 0;
  int l = strlen(Nome);

  for (i=0; i<l; i++) {
    sum += Nome[i];
  }
    return sum;
}

int calcForca(int inicio, int fim, int index) {
  int i;
  int result = 0;
  int pos = 1;
  // calcula pontos de B
  if(index == 1) {
    for(i=inicio; i<=fim; i++) {
      result += score[i]*pos;
      pos++;
    }
  }
  // calcula pontos de A
  else {
    for(i=fim; i>=inicio; i--) {
      result += score[i]*pos;
      pos++;
    }
  }
  return result;
}

int findEmpate(int inicio, int fim) {
  int meio;

  while(inicio <= fim) {
    meio = (inicio + fim)/2; 
    int pontosA = calcForca(inicio, meio, -1);
    int pontosB = calcForca(meio+1, fim, 1);

    if(pontosA == pontosB) {
      return meio;
    }
    else if(pontosA > pontosB) {
      fim = meio - 1;
    }
    else {
      inicio = meio + 1;
    }
  }
  return -1;
}


int main() {
  // variáveis de controle de fluxo:
  int i;
  // casos de teste:
  int n;

  while(scanf("%d", &n) && n != 0) {
    // vetor de nomes;
    char nome[n][11];
  
    // captura dos nomes dos competidores e as pontuações sem peso
    for(i=0; i<n; i++) {
      scanf("%s", nome[i]);
      score[i] = (long long int)getSize(nome[i]);
    }

    // procurando recursivamente o índice da solução
    int nameIndex = findEmpate(0, n-1);

      if(nameIndex == -1) {
        printf("Impossibilidade de empate.");
        printf("\n");
      }
      else {
        printf("%s", nome[nameIndex]);
        printf("\n");
      }
  }  


  return 0;
}