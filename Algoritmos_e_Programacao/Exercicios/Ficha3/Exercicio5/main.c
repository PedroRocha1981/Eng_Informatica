/*
Escreva uma função que determine o maior de dois números dados. Teste a função num pequeno
programa.
 * */

#include <stdio.h>
#include <locale.h>

int maior(int a, int b){
	if (a > b) return a;
	
	return b;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int a = 0, b = 0;
	
	printf("Insira um número inteiro: ");
	scanf("%d", &a);
	printf("\nInsira um número inteiro: ");
	scanf("%d", &b);
	
	printf("\nO maior dos dois números inseridos é %d!\n", maior(a, b));
	
	printf("\n"); //adiciona uma linha em branco
	
	return 0;
}
