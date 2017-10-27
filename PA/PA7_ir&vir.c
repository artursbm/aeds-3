#include <stdio.h>
#include <stdlib.h>

// ----------------- PA 7: IR E VIR ---------------- //
//               Problema 1128 do URI                //
// --------------------------------------------------//

int adj[2001][2001];
int t_adj[2001][2001];
int n, m;

void DFSaux(int v, int visited[], int flag) {
  int i,j;
  visited[v] = 1;
  if(flag == 1){
    for(j=0; j<n; j++) {
      if(adj[v][j] == 1) {
        if(!visited[j]) {
          DFSaux(j, visited, 1);
        }
      }
    }
  }
  else if(flag == -1) {
    for(j=0; j<n; j++) {
      if(t_adj[v][j] == 1) {
        if(!visited[j]) {
          DFSaux(j, visited, -1);
        }
      }
    }
  }
}

int DFS(int v) {
  int visited[n];
  int i,j;

  for(i=0; i<n; i++) {
    visited[i] = 0;
  }
    DFSaux(v, visited, 1);
  for(i=0; i<n; i++) {
    if(visited[i] == 0) {
      return 0;
    }
  }
  for(i=0; i<n; i++) {
    visited[i] = 0;
  }
    DFSaux(v, visited, -1);
  for(i=0; i<n; i++) {
    if(visited[i] == 0) {
      return 0;
    }
  }
  return 1;
}

int main()
{
  // interseções (V e W) e direcionamento do grafo (P), se único ou duplo
  int V, W, P;
  int i, j;
  
  // início dos casos de teste
  while (scanf("%d", &n) && n != 0 && scanf("%d", &m) && m != 0) {
    
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        adj[i][j] = 0;
        t_adj[i][j] = 0;
      }
    }
    // leitura para construir grafo
      for (j=0; j<m; j++) {
        scanf("%d", &V);
        scanf("%d", &W);
        scanf("%d", &P);
        if(P==1) {
          adj[V-1][W-1] = 1;
        }
        else if(P==2) {
          adj[V-1][W-1] = 1;
          adj[W-1][V-1] = 1;
        }
      }

    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        t_adj[i][j] = adj[j][i];
      }
    }
      int res = DFS(0);
      if(res == 1) {
        printf("1\n");
      } else {
        printf("0\n");
      }
  }
  return 0;
}