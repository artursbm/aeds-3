#include <stdio.h>
#include <string.h>
/*
    O programa precisa captar o intervalo de B a E, e printar esse intervalo;
Depois, precisa printar o reflexo desse intervalo, ou seja, inverter os algarismos 
caso seja maior ou igual a 10 (no caso de 10, printar 01 no reflexo); 
Para tanto, o que vou precisar será: 
    #transformar o intervalo numa string
    #colocar essa string numa string com 2x maior
    #inverter a primeira string e colocar numa segunda
    #colocar a segunda string no resto da string grande

    recebe int n
    converte n para string str1
    int size_str_espelho = 2*sizeof(str1)
    string str_espelho[size_str_espelho];
        for(i entre 0 e sizeof(str1)) {str_espelho[i] = str1[i]};
    inverte n
    converte n para string str2
        for(i entre sizeof(str1)+1 e size_str_espelho) {str_espelho[i] = str2[i]};

*/
int main() {
    int C, B, E;
    int i, j, k, key;    
    int s = 0; //tamanho de str1;

    //pegar o número de testes
    scanf("%d", &C); 
    for(i=0; i<C; i++) {
        //pega os valores de cada teste
        scanf("%d", &B);
        scanf("%d", &E);
        key = B;
        char str1[100000];
        char str_espelho[200000];
        for(j=0; j<E-B+1; j++) {
            sprintf(str1, "%s%d", str1,key++);
        }
        sprintf(str_espelho, "%s", str1);       
        char temp[100000];
        s = strlen(str1);
        //invertendo a string str1 para concatenar ao str_espelho    
            for (j=s-1, k=0; j>=0; j--, k++) {
                temp[k] = str1[j];
            }
            temp[k] = '\0';
            
        sprintf(str_espelho, "%s%s", str_espelho, temp);
        
            puts(str_espelho);               
    }
    return 0;
}