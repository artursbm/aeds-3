#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matriz.h"
#include "dados.h"

int main() {
    
    //variáveis de entrada
    int N, M;
    //variáveis de controle
    int i=0;
    //estruturas de manipulação
    struct elemento** matrix;
    int* vector;

    //início do programa
    if(scanf("%d", &N) > 0) {};
    if(scanf("%d", &M) > 0) {};
        vector = createVector(N);
        matrix = insertToMatrix(vector,N);

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
                matrix = updateMatrix(matrix, vector, N);
        }
        else if(!strcmp(ordem, "Sub")) {
            subFromInterval(vector, B, E);
                matrix = updateMatrix(matrix, vector, N);
        }
        else if(!strcmp(ordem, "Min")) {
            int min;
                min = getMin(matrix, B, E);
            printf("%d", min);
            printf("\n");
        }
        else if(!strcmp(ordem, "Max")) {
            int max;
                max = getMax(matrix, B, E);
            printf("%d", max);
            printf("\n");
        }
        else if(!strcmp(ordem, "Sum")) {
            int sum;
                sum = getSum(matrix, B, E);
            printf("%d", sum);
            printf("\n");
        }
        else {};
    }
    //O programa terminou, antes libero as memórias alocadas
    deleteVector(vector);
    deleteMatrix(matrix, N);
   
        return 0;
}