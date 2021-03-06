#include <stdio.h>
#include <string.h>

// ------- PA 5: CABO DE GUERRA --------- //
//                                        //
// ---------------------------------------// 
long long int score[200000];
int n;

long long int getSize(char *Nome) {
  int i;
  long long int sum = 0;
  int l = strlen(Nome);

  for (i=0; i<l; i++) {
    sum += (long long int)Nome[i];
  }
    return sum;
}

long long int calcForca(int inicio, int fim, int caso) {
  int i = 0;
  long long int result = 0;
  int peso = 1;
  // calcula força de A
  if(caso == 1) {
    for(i=fim; i>=inicio; i--) {
      result += score[i]*peso;
      peso++;
    }
  }
  // calcula força de B
  else if(caso == -1) {
    for(i=inicio; i<fim; i++) {
      result += score[i]*peso;
      peso++;
    }
  }
  return result;
}

int findEmpate(int inicio, int fim) {
  int meio;
  while(inicio <= fim) {
    meio = (inicio + fim)/2; 
    long long int pontosA = calcForca(0, meio, 1);
    long long int pontosB = calcForca(meio+1, n, -1);

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
  return n+1;
}

int main() {
  // variáveis de controle de fluxo:
  int i;
  
  // casos de teste:
  while(scanf("%d", &n) && n != 0) {
    // vetor de nomes;
    char nome[n][11];
  
    // captura dos nomes dos competidores e as pontuações sem peso
    for(i=0; i<n; i++) {
      scanf("%s", nome[i]);
      score[i] = getSize(nome[i]);
    }

    // procurando recursivamente o índice da solução
    int nameIndex = findEmpate(0, n-1);

      if(nameIndex == n+1) {
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