#ARQUIVOS DO PROGRAMA:
##  Há 2 arquivos main: 
* main_arvore 
* main_matriz
###  Arquivos matriz.h e matriz.c
A estrutura de dados matriz guarda as informações do vetor[N] da entrada
e suas respectivas tuplas de intervalo, todas em uma única matriz NxN;
A estrutura também suporta operações de inserção, consulta e atualização dessa matriz,
sendo essas funções:

* insert
* getMin
* getMax
* getSum
* update
###  Arquivos arvore.h e arvore.c
A estrutura de dados arvore guarda as informações do vetor[N] da entrada
e suas respectivas tuplas de intervalo, todas em uma árvore de segmentos alocada sequencialmente.
A estrutura também suporta operações de inserção, consulta e atualização dessa árvore,
sendo essas funções:

* createTree
* getMinSegTree
* getMaxSegTree
* getSumSegTree
* updateSegTree
###  Arquivos dados.h e dados.c
Arquivos que realizam operações sobre o vetor de tamanho N, com funções de criação (leitura da entrada e alocação), 
adição e subtração de unidade em um intervalo do vetor, liberação de memória do vetor. Esse arquivo também possui funções
que buscam os valores de minimo, maximo e soma de um intervalo dado.

* createVector
* addToInterval
* subFromInterval
* deleteVector
* setMin
* setMax
* setSum

###  Arquivo tuplas.h  
Um arquivo que declara a estrutura que guarda a tupla (min,max,sum) de intervalos do vetor;

### Entrada e Saída:
Um exemplo de entrada é dado (in_2.in) e a saída pode ser escrita no console ou no arquivo de saída, como os arquivos *.out dados.
O programa espera uma entrada N (tamanho do vetor), M(número de operações realizadas), os elementos do vetor (inseridos com separação por espaço), e as operações desejadas (Add, Sub, Min, Max e Sum). A compilação do programa gera dois arquivos finais:

* matriz
* arvore
