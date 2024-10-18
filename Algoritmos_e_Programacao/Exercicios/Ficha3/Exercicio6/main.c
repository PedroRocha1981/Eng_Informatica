/*
Elabore um programa que:
a) Leia as n componentes de um vetor;
b) Escreva as n componentes de um vetor;
c) Determine a posição em que se encontra a maior componente.
Cada uma destas tarefas deve ser realizada por uma função e testadas / corrigidas com o auxilio
de um outro pequeno programa.
 * */

#include <stdio.h>
#include <locale.h>

int pedirQuantidade(){
	int n = 0;
	
	do{
		printf("\nQuantos números vai inserir (mínimo 1 e máximo 20)? ");
		scanf("%d", &n);
	}while(n <= 0 || n > 20);
	
	return n;
}

void atribuirValores(int vec[], int n){
	for (int i = 0; i < n; ++i){
		printf("\nValor para posição %d: ", i + 1);
		scanf("%d", &vec[i]);
	}
}

void mostraValores(int vec[], int n){
	for (int i = 0; i < n; ++i)
		printf("\nO valor na posição %d do vetor é %d!", i + 1, vec[i]);
}

int posicaoMaior(int vec[], int n){
	int maior = vec[0];
	
	for (int i = 1; i < n; ++i)
		if (vec[i] > maior) maior = vec[i];
	
	return maior;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int vetor[20];
	int n = pedirQuantidade();
	
	atribuirValores(vetor, n);

	mostraValores(vetor, n);
	
	printf("\nO valor maior do vetor está na posição %d: ", posicaoMaior(vetor, n));
	
	printf("\n");
	
	return 0;
}
