/*
Considere uma matriz quadrada com nxn elementos inteiros.
Elabore um programa que lhe permita:
. Ler os nxn elementos da matriz;
. Mostrar no monitor os nxn elementos da matriz;
. Determinar o valor mínimo da matriz;
. Verificar se a matriz é ou não simétrica;
. Determinar a transposta da matriz;
. Calcular a soma de duas matrizes dadas.
Cada tarefa deve ser realizada por uma função.
 * 
 * */

#include <stdio.h>
#include <locale.h>

#define MAX 20

void preencheVetor(int vetor[][MAX], int num_componentes);
void visualizaVetor(int vetor[][MAX], int dim);
void trocaPos(int vec[][MAX], int l1, int c1, int l2, int c2);
int valorMin(int vetor[][MAX], int dim);
int valorMax(int vetor[][MAX], int dim);
short matrizSimetrica(int vetor[][MAX], int dim);
void determinaTransposta(int vetor[][MAX], int dim);
void somaMatrizes(int vec[][MAX], int vec2[][MAX], int dim);

int main()
{
	int vetor[MAX][MAX], vetor2[MAX][MAX], n_comp;
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		printf("\nInsira o número de linhas/colunas da matriz quadrada: ");
		scanf("%d", &n_comp);
	}while(n_comp <=0 || n_comp > MAX);
	
	printf("\nPREENCHER MATRIZ\n");
	preencheVetor(vetor, n_comp);
	
	visualizaVetor(vetor, n_comp);
		
	printf ("\nO valor mínimo na matriz é %d!", valorMin(vetor, n_comp));
	printf ("\nO valor máximo na matriz é %d!", valorMax(vetor, n_comp));
	
	if (n_comp >= 1){
		printf("\nA Matrix %s simétrica!", (matrizSimetrica(vetor, n_comp) == 0) ? "não é" : "é");
		
		printf("\n\nA TRANSPOSTA\n\n");
		determinaTransposta(vetor, n_comp);
		
		printf("\nInsira outra matrix %dx%d para somar com a anterior:\n", n_comp, n_comp);
		preencheVetor(vetor2, n_comp);
		
		printf("\n");
		visualizaVetor(vetor, n_comp);
		printf("+\n");
		visualizaVetor(vetor2, n_comp);
		printf("=\n");
		somaMatrizes(vetor, vetor2, n_comp);
		
	}else printf("\nA MATRIZ É DEMASIADO PEQUENA PARA VERIFICAR SIMETRÍA OU PERMUTAR!\n");
	
	printf("\n");
	
	return 0;
}


/*****
 * 
 * FUNÇÕES
 * 
******/

void somaMatrizes(int vec[][MAX], int vec2[][MAX], int dim){
	for (int i = 0; i < dim; ++i){
		printf("L%d ", i+1);
		for (int j = 0; j < dim; ++j)
			printf("[%d] ", vec[i][j] + vec2[i][j]);
		printf("\n");
	}
}

void determinaTransposta(int vetor[][MAX], int dim){
	for (int col = 0; col < dim; ++col){
		printf("L%d ", col+1);
		for (int ln = 0; ln < dim; ++ln)
			printf("[%d] ", vetor[ln][col]);
		printf("\n");
	}
}


short matrizSimetrica(int vetor[][MAX], int dim){
	
	/************
	 * [1 2 3  4
	 *  2 1 33 5
	 *  3 33 1 7
	 *  4 5  7 1]
	 * 
	 * l - 0 a n-2
	 * c - 0 a n-2
	 * 
	 * l0 - 1 a 3 = c0 - 1 a 3 ... l2 - 3 = c2 - 3
	 * 
	 * 0 123
	 * 1 23
	 * 2 3
	 * 
	 * *****/
	
	for (int ln = 0; ln <= dim - 2; ++ln) //percorre as linhas - 2
		for (int col = ln + 1; col < dim; ++col) //percorre as colunas
			if (vetor[ln][col] != vetor[col][ln]) return 0; //retorna falso caso haja diferença
	
	return 1;
}

void preencheVetor(int vetor[][MAX], int num_componentes){
	for (int i = 0; i < num_componentes; ++i)
		for (int j = 0; j < num_componentes; ++j){
			printf("\nValor na posição [%d][%d]: ", i+1, j+1);
			scanf("%d", &vetor[i][j]);
		}
}

void visualizaVetor(int vetor[][MAX], int dim){
	for (int i = 0; i < dim; ++i){
		printf("L%d ", i+1);
		for (int j = 0; j < dim; ++j)
			printf("[%d] ", vetor[i][j]);
		printf("\n");
	}

	
	printf("\n");
}

void trocaPos(int vec[][MAX], int l1, int c1, int l2, int c2){
	int temp = vec[l1][c1];
	
	vec[l1][c1] = vec[l2][c2];
	vec[l2][c2] = temp;
}

int valorMin(int vetor[][MAX], int dim){
	int min = vetor[0][0];
	
	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j)
			if (vetor[i][j] < min) min = vetor[i][j];
	
	return min;
}

int valorMax(int vetor[][MAX], int dim){
	int max = vetor[0][0];
	
	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j)
			if (vetor[i][j] > max) max = vetor[i][j];
	
	return max;
}
