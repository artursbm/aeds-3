#include <stdio.h>

int main() {
    int N=0; //2<N<100
    int meio=0, i=0, j=0, k=0, l=0, pos=0;
    while(scanf("%d", &N) != EOF) {
        int row=0;
        row = (N+1)/2; //numero de linhas da arvore (altura);
        meio = (N-1)/2; //posição do asterisco central;

        for(i=0; i<row; i++) {
            k=i+i+1;
            pos = meio-i;
            for(j=0; j<N; j++) {
                if(j<pos) {
                    printf(" ");
                }
                else {
                    for(l=0; l<k; l++) {
                        printf("*");
                    }
                    j=N+1;
                }
            }
            printf("\n");
        }
        for(i=0; i<meio; i++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
        for(i=0; i<meio-1; i++) {
            printf(" ");
        }
        for(i=0; i<3; i++) {
            printf("*");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}
