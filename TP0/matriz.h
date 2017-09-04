/* Header de uma estrutura de matriz que guarda em cada posição [i,j],
uma tupla do tipo (min,max,sum), calculada a partir do intervalo de
um vetor de n posições, V[v0,v1,...,vN]; a tupla será um struct elemento
que contém 3 chaves (min, max e sum), para guardar os valores citados acima.
*/

#ifndef _H_MATRIZ
#define _H_MATRIZ

#include "tuplas.h"
#include "dados.h"

//A matriz será composta de elementos, que contem o array com (min, max, sum)

//função para alocar matriz dinamicamente
//N será o tamanho do vetor, e representa
//a matriz de tuplas de tamanho NxN;
struct elemento** createMatrix(int N);

//função para inserir elemento na matriz
struct elemento** insertToMatrix(int* vector, int N);

//----------//Funções de Query da Matriz//----------//
//função para retornar o valor MIN da tupla 
//do intervalo [B,E] armazenado em M
int getMin(struct elemento** M, int B, int E);

//função para retornar o valor MAX da tupla 
//do intervalo [B,E] armazenado em M
int getMax(struct elemento** M, int B, int E);

//função para retornar o valor SUM da tupla 
//do intervalo [B,E] armazenado em M
int getSum(struct elemento** M, int B, int E);
//----------//--------------------------//----------//

//Função que atualiza a matriz de tuplas
//colocando novos valores após modificação do vetor
struct elemento** updateMatrix(struct elemento** M, int* vector, int N);

//função para liberar memória alocada
void deleteMatrix(struct elemento** m, int N);

#endif
