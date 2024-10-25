/*
 *Dado um vetor x com n componentes inteiras, escreva funções que permitam realizar as seguintes
operações:
a) Trocar a componente da posição p com a da posição q.
b) Efetuar a permutação circular do vetor dado;
Obs.: Crie um main() que lhe permita testar as funções criadas nos exercícios 7 e 8.
 * 
 * */

#include <stdio.h>
#include <locale.h>

#define MAX 20

void trocaPos(int vec[], int pos1, int pos2);
void permutaCircular(int vec[], int dim);
void preencheVetor(int vetor[], int num_componentes);
void visualizaVetor(int vetor[], int dim);
int pedirPosicao(int pos, int dimensao_vetor);

int main()
{
	int vetor[MAX], n_comp = 0, pos1 = 0, pos2 = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		printf("\nInsira o tamanho (número de componentes) dos vetores: ");
		scanf("%d", &n_comp);		
	}while(n_comp <=0 || n_comp > MAX);
	
	printf("\nVETOR A PREENCHER\n");
	preencheVetor(vetor, n_comp);
	
	if (n_comp >= 2){
		printf("\nTroca da posição de 2 valores no vetor\n");
		
		visualizaVetor(vetor, n_comp);
		pos1 = pedirPosicao(1, n_comp);
		pos2 = pedirPosicao(2, n_comp);
		
		printf("\nVetor atual:\n");
		visualizaVetor(vetor, n_comp);
		trocaPos(vetor, pos1, pos2);
		
		printf("\nVetor alterado:\n");
		visualizaVetor(vetor, n_comp);
		
		permutaCircular(vetor, n_comp);
		printf("\nVetor com permuta circular:\n");
		visualizaVetor(vetor, n_comp);		
	}else printf("\nO VETOR É DEMASIADO PEQUENO PARA TROCAR POSIÇÕES OU PARA PERMUTA CIRCULAR!\n");
	
	
	return 0;
}


/*****
 * 
 * FUNÇÕES
 * 
******/

void trocaPos(int vec[], int pos1, int pos2){
	int temp = vec[pos1];
	
	vec[pos1] = vec[pos2];
	vec[pos2] = temp;
}

void permutaCircular(int vec[], int dim){
	for (int i = 0, j = dim - 1; i < dim/2; ++i, --j){
		trocaPos(vec, i, j);
	}
}

void preencheVetor(int vetor[], int num_componentes){
	for (int i = 0; i < num_componentes; ++i){
		printf("\nValor na posição %d: ", i+1);
		scanf("%d", &vetor[i]);
	}
}

void visualizaVetor(int vetor[], int dim){
	for (int i = 0; i < dim; ++i)
		printf("%d ", vetor[i]);
	
	printf("\n");
}

int pedirPosicao(int pos, int dimensao_vetor){
	int p = 0;
	
	do{
		printf("\nPosição %d a trocar de 1 a %d: ", pos, dimensao_vetor);
		scanf("%d", &p);
		if (p <= 0 || p > dimensao_vetor) printf("\nA posição tem que estar compreendida entre 1 e %d!!!", dimensao_vetor);
	}while (p <= 0 || p > dimensao_vetor);
	
	return p-1;
}

