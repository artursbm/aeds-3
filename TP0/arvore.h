/*Header de declaração de um TAD tipo árvore de segmentos, 
com as seguintes operações sobre os dados: 
-> inserção;
-> busca;
-> atualização;
A segtree será armazenada sequencialmente conforme especificação,
e a estrutura do array se dará da seguinte forma:
Serão necessários (2*N-1) nós para guardar 
todos os valores de intervalos na árvore. O primeiro item do array
contém a raíz, ou seja, a tupla que representa o intervalo correspondente 
ao vetor de inteiros completo, intervalo [1:N]; Nos próximos índices da segtree,
serão guardados os intervalos subseguintes, como se fosse contado de cima para baixo,
e da esquerda para a direita na etrutura de uma árvore. Algumas folhas ficarão vazias,
caso a árvore não seja uma potência de 2. Os espaços vazios no vetor não terão nenhuma
interferência na execução dos algoritmos;
A árvore será armazenada num vetor de tamanho (2^(height+1)) - 1;
*/

#ifndef _H_ARVORE
#define _H_ARVORE

#include "tuplas.h"
#include "dados.h"
struct SegTree {
    struct elemento node;
};

//Funções para auxiliar no cálculo da altura da árvore//
//Função auxiliar que calcular resultado de base^exp
int pot(int base, int exp);
//Função auxiliar de cálculo de logaritmo na base 2
int log_2(int N);
//----------------------------------------------------//

//Função auxiliar de estruturação recursiva da árvore de segmentos,
//dados um vetor, um intervalo [B:E], uma estrutura SegTree e o índice do nó a ser inserido 
void insertToTree(int* vector, struct SegTree* arvore, int index,  int B, int E);

//Função para criar e inserir os valores do vetor na árvore
//árvore terá (2*N - 1) nós preenchidos, sendo N folhas e (N-1) nós intermediários
//Para implementar de forma sequencial essa árvore, algumas posições do "vetor de nós"
//ficarão vazias, pois não correspondem a nós de dados válidos ou participantes do vetor 
//de dados ou de tuplas.
struct SegTree* createSegTree(int* vector, int N);

//----------//Funções de Query da segtree//----------//
//Função recursiva auxiliar para retornar o valor Mínimo do intervalo (pegar arvore[i].node.min)
int getMinAux(struct SegTree* arvore, int L, int R, int B, int E, int index);
//Função para retornar o valor Mínimo de um dado intervalo [B,E]
int getMinSegTree(struct SegTree* arvore, int B, int E, int N);

//Função recursiva auxiliar para retornar o valor Máximo do intervalo (pegar arvore[i].node.max)
int getMaxAux(struct SegTree* arvore, int L, int R, int B, int E, int index);
//Função para retornar o valor Máximo de um dado intervalo [B,E]
int getMaxSegTree(struct SegTree* arvore, int B, int E, int N);

//Função recursiva auxiliar para retornar a soma do intervalo (pegar arvore[i].node.sum)
int getSumAux(struct SegTree* arvore, int L, int R, int B, int E, int index);
//Função para retornar o valor da Soma de um dado intervalo [B,E]
int getSumSegTree(struct SegTree* arvore, int B, int E, int N);
//----------//---------------------------//----------//

//---------//Funções de Update da segtree//----------//
//Função recursiva auxiliar para update da segtree
void updateTreeAux(struct SegTree* arvore, int L, int R, int B, int E, int index, int dif);
//Função para atualizar valores da árvore
struct SegTree* updateSegTree(struct SegTree* arvore, int N, int B, int E, int dif);    
//---------//----------------------------//----------//

//Função para liberar memória alocada pela segtree
void deleteSegTree(struct SegTree* arvore);

#endif

