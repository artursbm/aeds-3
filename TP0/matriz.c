#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct elemento** createMatrix(int N){ 
    struct elemento** m;
    int i=0;
    m = malloc(N * sizeof(struct elemento*));
    for(i=0; i<N; i++) {
        m[i] = malloc(N * sizeof(struct elemento));
    }
    return m;
}

struct elemento** insertToMatrix(int* vector, int N){
    struct elemento** m; 
    m = createMatrix(N);
    int i, j;
        for(i=0; i<N; i++) { 
            for(j=0; j<N; j++) {
                if(i<=j){
                    m[i][j].min = setMin(vector, i+1, j+1);
                    m[i][j].max = setMax(vector, i+1, j+1);
                    m[i][j].sum = setSum(vector, i+1, j+1);
                }
                else {
                    m[i][j].min = setMin(vector, j+1, i+1);
                    m[i][j].max = setMax(vector, j+1, i+1);
                    m[i][j].sum = setSum(vector, j+1, i+1);
                }
            }
        }
    return m;
}

int getMin(struct elemento** M, int B, int E) {
    return(M[B-1][E-1].min);
}

int getMax(struct elemento** M, int B, int E) {
    return(M[B-1][E-1].max);
}

int getSum(struct elemento** M, int B, int E) {
    return(M[B-1][E-1].sum);
}

struct elemento** updateMatrix(struct elemento** M, int* vector, int N) {
    deleteMatrix(M, N);
    M = insertToMatrix(vector, N);
    return M;
}

void deleteMatrix(struct elemento** m, int N) {
    int i=0;
    for(i=0; i<N; i++) {
        free(m[i]);
    }
    free(m);
}