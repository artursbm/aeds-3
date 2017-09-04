#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "dados.h"

int main() {
    //variáveis de entrada
    int N, M;
    //variáveis de controle
    int i=0;
    //estruturas de manipulação
    struct SegTree* arvore;
    int* vector;

    //início do programa
    if(scanf("%d", &N) > 0) {};
    if(scanf("%d", &M) > 0) {};
        vector = createVector(N);
        arvore = createSegTree(vector, N);

    //programa então recebe as operações e consultas
    for(i=0; i<M; i++) {
        //variaveis de operação
        int B, E;
        char ordem[3];

        //Leitura das operações
        if(scanf("%s", ordem) > 0) {};
        if(scanf("%d", &B) > 0) {};
        if(scanf("%d", &E) > 0) {};

        //Casos das operações e açoes relacionadas
        if(!strcmp(ordem, "Add")) {
            addToInterval(vector, B, E);
                arvore = updateSegTree(arvore, N, B, E, 1);
        }
        else if(!strcmp(ordem, "Sub")) {
            subFromInterval(vector, B, E);
                arvore = updateSegTree(arvore, N, B, E, -1);
        }
        else if(!strcmp(ordem, "Min")) {
            int min;
                min = getMinSegTree(arvore, B, E, N);
            printf("%d", min);
            printf("\n");
        }
        else if(!strcmp(ordem, "Max")) {
            int max;
                max = getMaxSegTree(arvore, B, E, N);
            printf("%d", max);
            printf("\n");
        }
        else if(!strcmp(ordem, "Sum")) {
            int sum;
                sum = getSumSegTree(arvore, B, E, N);
            printf("%d", sum);
            printf("\n");
        }
        else {};
    }
    //O programa terminou, antes libero as memórias alocadas
    deleteVector(vector);
    deleteSegTree(arvore);
    
    return 0;
}