#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------- PA N: TITULO DA PA --------- //
//               Problema XXXX do URI                //
// --------------------------------------------------// 

int grafo[51][51];
int labirinto[51][51];


int main() {
  int i=0;
  int j=0;
  char lab;
  int n, m;

  do {
    scanf("%d", &n);
    scanf("%d", &m);

    for(i=0; i<n; i++) {
      for(j=0; j<m; j++) {
        labirinto[i][j] = 0;
        grafo[i][j] = 0;
      }
    }

    for(i=1; i<=n; i++) {
      for(j=1; j<=m; j++) {
        scanf(" %c", &lab);
        if(lab == '.') {
          labirinto[i][j] = 1;
        } else {
          labirinto[i][j] = 0;
        }
      }
    }
     
        printf("\n");

    for(i=0; i<n; i++) {
      for(j=0; j<m; j++) {
        printf("%d ", labirinto[i][j]);
      }
      printf("\n");
    }

  } while(n!=0 && m!=0);

  


  return 0;
}