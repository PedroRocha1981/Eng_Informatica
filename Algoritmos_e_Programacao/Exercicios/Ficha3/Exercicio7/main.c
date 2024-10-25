/*
 * Escreva uma função que determine o produto interno de dois vetores de n componentes inteiras. * 
 * 
 * */

#include <stdio.h>
#include <locale.h>

#define MAX 20 //valor maximo 

long int produtoVetores(int vetor_a[], int vetor_b[], short num_componentes);
void preencheVetor(int vetor[], int num_componentes);

int main()
{
	int vetor1[MAX], vetor2[MAX]; //define os vetores
	short n_comp = 0; //variável para guardar o número de componentes a usar MAX 20
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		printf("\nInsira o tamanho (número de componentes) dos vetores: ");
		scanf("%d", &n_comp);
	}while (n_comp <= 0 || n_comp > MAX);
	
	//vai pedir ao utilizador os dados para os vetores
	printf("\nVETOR 1\n");
	preencheVetor(vetor1, n_comp);
	
	printf("\nVETOR 2\n");
	preencheVetor(vetor2, n_comp);
	
	printf("\nO produto dos 2 vetores unidimensionais é %ld!\n", produtoVetores(vetor1, vetor2, n_comp));
	
	return 0;
}


/*****
 * 
 * FUNÇÕES
 * 
******/

long int produtoVetores(int vetor_a[], int vetor_b[], short num_componentes){
	long int produto = 0;
	
	for (int i = 0; i < num_componentes; ++i)
		produto += vetor_a[i] * vetor_b[i];
	
	return produto;
}

void preencheVetor(int vetor[], int num_componentes){
	for (int i = 0; i < num_componentes; ++i){
		printf("\nValor na posição %d: ", i+1);
		scanf("%d", &vetor[i]);
	}
}
