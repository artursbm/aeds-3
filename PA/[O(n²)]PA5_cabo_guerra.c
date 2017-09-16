#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------- PA 5: CABO DE GUERRA --------- //
//     Essa solução funciona em O(n²);    //
// ---------------------------------------// 

int getSize(char *Nome) {
  int i, sum = 0;
  int l = strlen(Nome);

  for (i=0; i<l; i++) {
    sum += Nome[i];
  }
    return sum;
}

int main() {
  // variáveis úteis
  int i, j, k, sum, coragem;
  // flag de nome achado
  int achou = 0;
  // força total das equipes
  int strengthA = 0;
  int strengthB = 0;
  // casos de teste:
  int n;


  while(scanf("%d", &n) && n != 0) {
    // vetor de nomes;
    char nome[n][10];
    // captura dos nomes dos competidores
    for(i=0; i<n; i++) {
      scanf("%s", nome[i]);
    }
    //comparação das possibilidades de equipes
    for(i=0; i<n-1; i++) {
      // inicializando as variáveis de controle a cada loop
      strengthA = 0;
      strengthB = 0;
      coragem=1;

      for(j=i+1; j<=n-1; j++) {
        sum = coragem*getSize(nome[j]);
        strengthB += sum;
        coragem++;
      }

      coragem=1;
      for(k=i; k>=0; k--) {
        sum = coragem*getSize(nome[k]);
        strengthA += sum;
        coragem++;
      }
      if(strengthA == strengthB) {
        achou = 1;
        break;
      }
    }
    if(i == n-1) {
      printf("Impossibilidade de empate.");
      printf("\n");
    }
    else {
      puts(nome[i]);
    }
  }
  return 0;
}