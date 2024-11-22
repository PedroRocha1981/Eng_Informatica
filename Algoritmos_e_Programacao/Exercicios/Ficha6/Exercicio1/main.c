/*
 * Elabore um programa que realize as operações a seguir indicadas, com matrizes de dimensão
variável e que onde seja permitido registar dados do tipo inteiro ou real, ambos especificados pelo
utilizador:
a) Alocação dinâmica de memória para armazenar uma matriz com um número de linhas e
colunas indicado pelo utilizador;
b) Leitura, por linhas, das componentes da matriz;
c) Escrita, por linhas, das componentes da matriz;
d) Cálculo do TRAÇO (soma das componentes da diagonal principal);
e) Verificação da existência de simetria relativamente à diagonal principal.
 * 
 * 
 * */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>

enum Tipo{
	INTEIRO,
	FLOAT
};

enum LinCol{
	LINHAS,
	COLUNAS
};

//prototipagem
enum Tipo perguntaTipo(); //pergunta tipo de dados da matriz
void limpaEcra(); //limpa o ecrã
int recolheLinhasColunas(enum LinCol num); //pergunta o número de linhas ou colunas
//calcula os traços de cada tipo de matriz
long calculaTracoInteiro(int *matriz, int dim);
double calculaTracoFloat(float *matriz, int dim);
//calcula simetria de cada matriz
char simetriaInteiro(int *matriz, int dim);
char simetriaFloat(float *matriz, int dim);
//pedir ao utilizador número
int pedeInteiro(int linha, int coluna);
float pedeFloat(int linha, int coluna);
//mostra a matriz introduzida
void mostraMatrizInteira(int *matriz, int linhas, int colunas);
void mostraMatrizFloat(float *matriz, int linhas, int colunas);


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	//matrizes dinâmicas
	float *matriz_float;
	int *matriz_int;
	//linhas e colunas;
	int linhas = 0, colunas = 0;
	//tipo de dados a recolher
	enum Tipo tipo;
	
	//pergunta o tipo de dados a inserir
	tipo = perguntaTipo();
	
	//pergunta as linhas e colunas
	linhas = recolheLinhasColunas(LINHAS);
	colunas = recolheLinhasColunas(COLUNAS);
	
	printf("\nLinhas %d, Colunas %d\n", linhas, colunas);
	
	//vai alocar memória para a matriz correspondente
	if (tipo == INTEIRO){
		matriz_int = (int *)malloc((linhas * colunas) * sizeof(int));
		//printf("\nTamanho %ld de %ld", sizeof(matriz_int), sizeof(int));
		
		if (matriz_int == NULL) {
			printf("\nFalhou a alocação de memória!\n");
			return 1;
		}
	}else {
		matriz_float = (float *)calloc(linhas * colunas, sizeof(float));
		//printf("\nTamanho %ld de %ld", sizeof(matriz_float), sizeof(float));
		
		if (matriz_float == NULL) {
			printf("\nFalhou a alocação de memória!\n");
			return 1;
		}
	}
	
	//pedir ao utilizador os elementos da tabela
	for (int i = 0; i < linhas; ++i)
		for (int j = 0; j < colunas; ++j)
			if (tipo == INTEIRO){
				matriz_int[i * colunas + j] = pedeInteiro(i+1, j+1);
			}else{
				matriz_float[i * colunas + j] = pedeFloat(i+1, j+1);
			}
	
	//mostra a matriz inteira ou float depois de limpar o ecrã
	limpaEcra();
	if (tipo == INTEIRO){
		mostraMatrizInteira(matriz_int, linhas, colunas);
	}else{
		mostraMatrizFloat(matriz_float, linhas, colunas);
	}
	
	//verifica se a matriz é quadrada para efetuar as operações do enunciado
	if (linhas == colunas){
		//matriz quadrada: vai efetuar as operações
		
		if (tipo == INTEIRO){
			//traço
			printf("\nO traço da matriz é de %ld!\n", calculaTracoInteiro(matriz_int, linhas));
			
			//simetria
			printf("\nA Matrix %s simétrica!", (simetriaInteiro(matriz_int, linhas) == '0') ? "não é" : "é");
		}else{
			//traço
			printf("\nO traço da matriz é de %0.2lf!\n", calculaTracoFloat(matriz_float, linhas));
			
			//simetria
			printf("\nA Matrix %s simétrica!", (simetriaFloat(matriz_float, linhas) == '0') ? "não é" : "é");
		}
		
	}else{
		printf("\nO número de Linhas difere do número de colunas!\nLogo a matriz não é quadrada para as operações seguintes!\n");
		return 0; //sai do programa
	}
	
	//libertar os ponteiros da memória
	if (tipo == INTEIRO){
		free(matriz_int);
	}else{
		free(matriz_float);
	}
	
	printf("\n");
	return 0;
}

/**
* 
* FUNÇÕES
*
**/
void mostraMatrizFloat(float *matriz, int linhas, int colunas){
	printf("\n\n[");
	for(int i = 0; i < linhas; ++i){
		for(int j = 0; j < colunas; ++j)
			printf(" %0.2f", matriz[i * colunas + j]);
		if (i < linhas - 1) printf("\n"); //muda para a linha seguinte e dá um espaço
	}
	printf(" ]\n");
}

void mostraMatrizInteira(int *matriz, int linhas, int colunas){
	printf("\n\n[");
	for(int i = 0; i < linhas; ++i){
		for(int j = 0; j < colunas; ++j)
			printf(" %d", matriz[i * colunas + j]);
		if (i < linhas - 1) printf("\n"); //muda para a linha seguinte e dá um espaço
	}
	printf(" ]\n");
}

int pedeInteiro(int linha, int coluna){
	int val = 0;
	printf("\nQual o valor Inteiro [%d][%d]: ", linha, coluna);
	scanf(" %d", &val);
	
	return val;
}

float pedeFloat(int linha, int coluna){
	float val = 0;
	printf("\nQual o valor Float [%d][%d]: ", linha, coluna);
	scanf(" %f", &val);
	
	return val;
}

char simetriaFloat(float *matriz, int dim){
	/*for (int ln = 0; ln <= dim - 2; ++ln) //percorre as linhas - 2
		for (int col = ln + 1; col < dim; ++col) //percorre as colunas
			if (matriz[ln * dim + col] != matriz[col * dim + ln]) return '0'; //retorna falso caso haja diferença 
	*/
	for (int ln = 0; ln < dim - 1; ++ln)
		for (int col = ln + 1; col < dim; ++col)
			if (*(matriz + ln * dim + col) != *(matriz + col * dim + ln)) return '0';
	
	return '1';
}

char simetriaInteiro(int *matriz, int dim){
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
			if (matriz[ln * dim + col] != matriz[col * dim + ln]) return '0'; //retorna falso caso haja diferença 
	
	
	return '1';
}

double calculaTracoFloat(float *matriz, int dim){
	double soma = 0;
	int l;
	
	soma = *matriz;
	
	for (l = 1; l < dim; ++l)
		soma = soma + matriz[l * dim + l];
	
	return soma;
}

long calculaTracoInteiro(int *matriz, int dim){
	
	/*
	[1 2 3 4
	 2 2 4 6
	 3 1 1 4
	 5 6 7 9]
	
	 * traço = 1 + 2 + 1 + 9
	 * 
	 * 0,0; 1,1; 2,2; 3,3
	 * 
	 * linha * colunas + coluna
	 * 
	 * 0,0 = 0 * 4 + 0
	 * 
	 * */
	
	long soma = 0;
	int l;
	
	soma = *matriz;
	
	for (l = 1; l < dim; ++l)
		soma = soma + matriz[l * dim + l];
	
	return soma;
}

int recolheLinhasColunas(enum LinCol num){
	int numero = 0;
	
	printf("\nNúmero de %s\n(AS OPERAÇÕES SEGUINTES APENAS DÃO PARA MATRIZES QUADRADAS): ", (num == LINHAS) ? "Linhas": "Colunas");
	scanf(" %d", &numero);
	
	return numero;
}
 
void limpaEcra(){
	//limpa o ecrã, seja em windows ou macOS/Linux
	if (system("cls") != 0) system("clear");
}
 
enum Tipo perguntaTipo(){
	char op = ' ';
	char quit = '0';
	enum Tipo tip = INTEIRO;
	 
	limpaEcra();
	 
	do{
		printf("\n\nTIPO DE ELEMENTOS DA MATRIZ A LER\nI - Inteiro / F - Float: ");
		scanf(" %c", &op);
		 
		switch(op){
			case 'i':
			case 'I':
				tip = INTEIRO;
				quit = '1';
				break;
			case 'f':
			case 'F':
				tip = FLOAT;
				quit ='1';
				break;
			default:
				printf("\nOpção inválida!!");
				getchar();
		}
		 
	}while (quit == '0');
	
	return tip;
}
 
