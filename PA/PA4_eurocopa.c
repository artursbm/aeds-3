#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  struct Equipes {
    char nome[30];  
    int score;
    int jogos;
    int posicao;
  };

  int n=0; // numero de times do grupo; 1<=n<=20
  int i, caso=1;
  int g; // numero de jogos completos 
  
  
  while(scanf("%d", &n) && n != 0) {
    struct Equipes times[n];
      for(i=0; i<n; i++) {
        scanf("%s", times[i].nome);
        times[i].jogos = (n-1)*2;
        times[i].score = 0;
        times[i].posicao = 0;
      }
    scanf("%d", &g);
      for(i=0; i<g; i++) {
      }







    printf("\n");
  }
  
  return 0;
}
