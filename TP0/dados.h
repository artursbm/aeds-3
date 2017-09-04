/*Header da estrutura Dados que receberá um vetor V[v1,v2,...,vN]
e calculará os valores de (min, max, sum), armazenando-os em uma matriz
ou em uma arvore de segmentos. O objeto dados incluirá objetos matriz e 
arvore;
Terá funções de ADD (adicionar 1 a cada elemento do intervalo selecionado), 
SUB (subtrai 1 de cada elemento do intervalo selecionado), dentre outros.
*/

#ifndef _H_DADOS
#define _H_DADOS

#include "matriz.h"

//função para criar um vetor vazio com tamanho N
//e inserir elementos 
int* createVector(int N);
//função que soma 1 ao intervalo dado 
void addToInterval(int* vector, int B, int E);
//função que subtrai 1 do intervalo dado [B,E]
void subFromInterval(int* vector, int B, int E);
//liberando alocação do vetor
void deleteVector(int *v);
//encontra o minimo num intervalo [B,E]
int setMin(int* vector, int B, int E);
//encontra o maximo num intervalo [B,E]
int setMax(int* vector, int B, int E);
//encontra a soma dos elementos no intervalo [B,E]
int setSum(int* vector, int B, int E);

//saltar espaço
#endif