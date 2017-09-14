#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  struct Equipes {
    char nome[30];  
    int score;
    int pontuacao;
    int jogos_restantes;
    int posicao_pior;
    int posicao_melhor;
  };

  int n=0; // numero de times do grupo; 1<=n<=20
  int i,j, caso=1;
  int t1, t2;
  int g; // numero de jogos completos 
  
  
  while(scanf("%d", &n) && n != 0) {
    struct Equipes times[n];
      for(i=0; i<n; i++) {
        scanf("%s", times[i].nome);
        times[i].jogos_restantes = (n-1)*2;
        times[i].score = 0;
        times[i].pontuacao = 0;
        times[i].posicao_pior = n;
        times[i].posicao_melhor = 1;
      }
    scanf("%d", &g);
      for(i=0; i<g; i++) {
        // declaração e leitura de jogos e resultados
        char time1[30] = "";
        char time2[30] = "";
        int gols1, gols2;
        scanf("%s", time1);
        scanf("%s", time2);
        scanf("%d", &gols1);
        scanf("%d", &gols2);

        // descobrindo quais times jogaram
        // e atribuindo resultados
        for(j=0; j<n; j++) {
          if(strcmp(time1, times[j].nome) == 0) {
            t1 = j;
          }
        }
        for(j=0; j<n; j++) {
          if(strcmp(time2, times[j].nome) == 0) {
            t2 = j;
          }
        }
        // gols no jogo
        times[t1].score = gols1;
        times[t2].score = gols2;
        // jogos restantes
        times[t1].jogos_restantes--;
        times[t2].jogos_restantes--;
        // checando vitoria/derrota/empate
        if(gols1 > gols2) {
          // caso time 1 ganhe
          times[t1].pontuacao+=3;
        }
        else if(gols1 == gols2) {
          // caso empate
          times[t1].pontuacao++;
          times[t2].pontuacao++;
        }
        else {
          // caso time 2 ganhe
          times[t2].pontuacao+=3;
        }
      }
      for(i=0; i<n; i++) {
        for(j=0;j<n; j++) {
          
          if(i>=n) {
            int k=0, l=0;
            for(k=0; k<n; k++) {
              int melhor = 0;
              int pior = 0;
              for(l=0; l<n; l++) {
                if(times[l].pontuacao > times[l].pontuacao) melhor++;
                else  pior++;
              }
              if(times[k].posicao_melhor > melhor+1) times[k].posicao_melhor = melhor+1;
              if(times[k].posicao_pior > n - pior)  times[k].posicao_pior = (n-pior);
            }
          }
          if(i==j) {
            j++;
          }
        }
      }
      printf("Group #%d", caso);
      printf("\n");
      for(i=0; i<n; i++) {
        printf("%s %d-%d", times[i].nome, times[i].posicao_melhor, times[i].posicao_pior);
        printf("\n");
      }
      printf("\n");
      caso ++;
  }
  
  return 0;
}

