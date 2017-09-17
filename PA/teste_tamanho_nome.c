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

int i, n;
  scanf("%d", &n);
  char nome[n][10];
  int s2[n];
  int pos = 1;
  int ans = 0;
  // captura dos nomes dos competidores
  for(i=0; i<n; i++) {
    scanf("%s", nome[i]);

    s2[i] = getSize(nome[i]);
    ans += s2[i]*pos, ++pos;
    printf("getSize de %s: %d \n pos: %d, ans: %d \n\n", nome[i], s2[i], pos, ans);
    ans=0;
    
  }

  return 0;
}
