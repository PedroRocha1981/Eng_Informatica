/*
Implemente uma função que permita trocar o valor de duas variáveis. Teste a função num pequeno
programa para o efeito.
 * 
 * */

#include <stdio.h>
#include <locale.h>

void trocaVariaveis(int *a, int *b);

int main()
{
	int var1 = 0, var2 = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um valor para variável A: ");
	scanf("%d", &var1);
	printf("\nInsira um valor para variável B: ");
	scanf("%d", &var2);
	
	printf("\n\nA variável A tem valor %d e a variável B tem valor %d!", var1, var2);
	
	trocaVariaveis(&var1, &var2);
	printf("\nApós troca de valores, variável A tem valor %d e a variável B tem valor %d!", var1, var2);
	
	printf("\n");
	
	return 0;
}


/*****
 * 
 * FUNÇÕES
 * 
******/

void trocaVariaveis(int *a, int *b){
	int temp = *a;
	
	*a = *b;
	*b = temp;
}
