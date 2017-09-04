#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

int* createVector(int N) {
    int* v;
    v = malloc(N*sizeof(int));
    int i=0;
    //faz a leitura pela entrada de dados
    for(i=0; i<N; i++) {
        if (scanf("%d", &v[i]) > 0) {};
    }
    return v;
}

void addToInterval(int* vector, int B, int E) {
    int i;
    for(i=B-1; i<E; i++) {
        vector[i]++;
    }
}

void subFromInterval(int* vector, int B, int E) {
    int i;
    for(i=B-1; i<E; i++) {
        vector[i]--;
    }
}

int setMin(int* vector, int B, int E) {
    int i=0;
    int menor=vector[B-1];
    //compara para encontrar qual o menor valor
    //dentro do intervalo
    for(i=B; i<E; i++) {
        if(vector[i]<=menor){
     	    menor=vector[i];
        }
    }
    return menor;
}   

int setMax(int* vector, int B, int E) {
    int i=0;
    int maior = vector[B-1];
    //compara para encontrar qual o menor valor
    //dentro do intervalo
    for(i=B; i<E; i++) {
        if(vector[i]>=maior) {
            maior=vector[i];
        }
    }
    return maior;
}

int setSum(int* vector, int B, int E) {
    int i=0;
    int sum=0;
    //soma todos os elementos dentro do intervalo
    for(i=B-1; i<E; i++) {
        sum += vector[i];
    }
    return sum;
}

void deleteVector(int *v) {
    free(v);
}
