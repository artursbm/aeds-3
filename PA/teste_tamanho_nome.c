#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSize(char *Nome) {
  int i, sum = 0;
  int l = strlen(Nome);

  for (i=0; i<l; i++) {
    sum += Nome[i];
  }
    return sum;
}

int main() {

int forca = 0, i, n;
  scanf("%d", &n);
  char nome[n][10];
  // captura dos nomes dos competidores
  for(i=0; i<n; i++) {
    scanf("%s", nome[i]);
  }
    for(i=0; i<n; i++) {
      int sum = getSize(nome[i]);
      forca+=sum;
      printf("nome: %s, tamanho: %d \n", nome[i], sum);
    }
    printf("Força total: %d \n", forca);
  return 0;
}
