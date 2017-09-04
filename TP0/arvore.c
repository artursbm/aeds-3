#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int pot(int base, int exp)
{
	if(exp == 0) {
		return 1;
	}
	else if(exp == 1) {
		return base;
	}
	else {
		return (base*pot(base, exp-1));
	}
}

int log_2(int N) {
	if(N==1) {
		return 0;
	}
	else {
		return 1 + log_2(N/2);
	}
}

void insertToTree(int* vector, struct SegTree* arvore, int index,  int B, int E) {
	//caso base, em que o elemento visitado é um nó
	if(B==E) {
		arvore[index].node.min = setMin(vector, B+1, E+1);
		arvore[index].node.max = setMax(vector, B+1, E+1);
		arvore[index].node.sum = setSum(vector, B+1, E+1);
	}
	else {
		int M = B+(E-B)/2;
		//chamada recursiva para verificar em qual posição o intervalo ficará armazenado
		insertToTree(vector, arvore, (2*index+1), B, M);
		insertToTree(vector, arvore, (2*index+2), M+1, E);

		//comparação para definir o mínimo de qual nó filho é o menor
		if(arvore[2*index+1].node.min <= arvore[2*index+2].node.min) {
			arvore[index].node.min = arvore[2*index+1].node.min;
		}
		else {
			arvore[index].node.min = arvore[2*index+2].node.min;
		}

		//comparação para definir o máximo de qual nó filho é o maior
		if(arvore[2*index+1].node.max >= arvore[2*index+2].node.max) {
			arvore[index].node.max = arvore[2*index+1].node.max;
		}
		else {
			arvore[index].node.max = arvore[2*index+2].node.max;
		}
		//alocação do valor de soma, que é a soma das somas dos nós filhos
		arvore[index].node.sum = arvore[2*index+1].node.sum + arvore[2*index+2].node.sum;
	}
}

struct SegTree* createSegTree(int* vector, int N) {
	struct SegTree* arvore;
	int height = log_2(N) + 1;
	int size = pot(2,(height+1)) - 1;
	//A árvore será armazenada num vetor de tamanho (2^(height+1)) - 1;
	arvore = malloc((size) * sizeof(struct SegTree));
	//usa a função recursiva acima para inserir os elementos na 
	//segtree arvore a partir do vetor dado;
	insertToTree(vector, arvore, 0, 0, N-1);
	return arvore;
}

int getMinAux(struct SegTree* arvore, int L, int R, int B, int E, int index) {	
	//Se já estiver no nó do intervalo, retorno o valor mínimo;
	if(B<=L && E>=R) {
		return arvore[index].node.min;
	}
	//caso esteja fora dos limites de comparação,
	//retorno um infinito positivo virtual;
	else if(B>R || E<L) {
		return 2147483647;
	}
	//se não for o intervalo mas estiver meio dentro,
	//vou para os nós filhos e comparo o mínimo da direita com o 
	//mínimo da esquerda para checar qual é o menor, e retorno ele;
	else {
		int M = L+(R-L)/2;
		int min1 = getMinAux(arvore, L, M, B, E, (2*index+1));
		int min2 = getMinAux(arvore, M+1, R, B, E, (2*index+2));
		if(min1 <= min2) {
			return min1;
		}
		else {
			return min2;
		}
	}
}

int getMinSegTree(struct SegTree* arvore, int B, int E, int N) {
	return getMinAux(arvore, 0, N-1, B-1, E-1, 0);
}

int getMaxAux(struct SegTree* arvore, int L, int R, int B, int E, int index) {	
	//Se já estiver no nó do intervalo, retorno o valor mínimo;
	if(B<=L && E>=R) {
		return arvore[index].node.max;
	}
	//caso esteja fora dos limites de comparação,
	//retorno um infinito negativo virtual;
	else if(B>R || E<L) {
		return -2147483648;
	}
	//se não for o intervalo mas estiver meio dentro,
	//vou para os nós filhos e comparo o máximo da direita com o 
	//máximo da esquerda para checar qual é o maior, e retorno ele;
	else {
		int M = L+(R-L)/2;
		int max1 = getMaxAux(arvore, L, M, B, E, (2*index+1));
		int max2 = getMaxAux(arvore, M+1, R, B, E, (2*index+2));
		if(max1 >= max2) {
			return max1;
		}
		else {
			return max2;
		}
	}
}

int getMaxSegTree(struct SegTree* arvore, int B, int E, int N) {
	return getMaxAux(arvore, 0, N-1, B-1, E-1, 0);
}

int getSumAux(struct SegTree* arvore, int L, int R, int B, int E, int index) {	
	//caso base, dentro do intervalo correto retorno o valor
	if(B<=L && E>=R) {
		return arvore[index].node.sum;
	}
	else if(B>R || E<L) {
		return 0;
	}
	else {
		int M = L+(R-L)/2;
		return getSumAux(arvore, L, M, B, E, (2*index+1)) + 
				getSumAux(arvore, M+1, R, B, E, (2*index+2));
	}
}

int getSumSegTree(struct SegTree* arvore, int B, int E, int N) {
	return getSumAux(arvore, 0, N-1, B-1, E-1, 0);
}

void updateTreeAux(struct SegTree* arvore, int L, int R, int B, int E, int index, int dif) {
	//checa se a busca pelo nó a atualizar é realizável
	//caso base: nada acontece se 'out of bounds'
	if(L>R || L>E || R<B) {
		return;
	}
	//se estiver em um nó folha, atualiza o valor daquele nó
	else if(L==R) {
		arvore[index].node.sum += dif;
		arvore[index].node.min += dif;
		arvore[index].node.max += dif;
	}
	//caso contrário, vai para os nós filhos
	else{
		int M = L + (R-L)/2;
		updateTreeAux(arvore, L, M, B, E, (2*index+1), dif);
		updateTreeAux(arvore, M+1, R, B, E, (2*index+2), dif);
		//então, atualiza o nó pai:
		//sum será a soma das somas dos nós filhos
		//min será o menor valor do intervalo dos nós filhos
		//max será o maior valor do intervalo dos nós filhos
		//min e max são alocados de acordo com comparação:
		arvore[index].node.sum = arvore[2*index+1].node.sum + arvore[2*index+2].node.sum;
		//comparação para definir o mínimo de qual nó filho é o menor
		if(arvore[2*index+1].node.min <= arvore[2*index+2].node.min) {
			arvore[index].node.min = arvore[2*index+1].node.min;
		}
		else {
			arvore[index].node.min = arvore[2*index+2].node.min;
		}

		//comparação para definir o máximo de qual nó filho é o maior
		if(arvore[2*index+1].node.max >= arvore[2*index+2].node.max) {
			arvore[index].node.max = arvore[2*index+1].node.max;
		}
		else {
			arvore[index].node.max = arvore[2*index+2].node.max;
		}
	}
}

struct SegTree* updateSegTree(struct SegTree* arvore, int N, int B, int E, int dif) {
	updateTreeAux(arvore, 0, N-1, B-1, E-1, 0, dif);
	return arvore;
}

void deleteSegTree(struct SegTree* arvore) {
	free(arvore);
}
