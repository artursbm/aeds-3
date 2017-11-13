#ifndef _H_EXATO
#define _H_EXATO

typedef struct Set {
  int id;
  int weight;
}Set;

// será utilizada uma abordagem de programação dinâmica
int findMaxDemand(Graph* graph);


#endif