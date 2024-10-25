/*
Elabore um programa que leia uma string e escreva os dois primeiros caracteres no monitor.
 * 
 * */

#include <stdio.h>
#include <locale.h>


int main()
{
	char str[256];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira uma frase: ");
	gets(str);
	
	printf("\nFrase inserida:\n");
	puts(str);
	
	for (int i = 0; i < 2 ; ++i)
		if (str[i] != '\0') { printf("%c", str[i]); }
		else break;
	
	printf("\n");
	
	return 0;
}


/*****
 * 
 * FUNÇÕES
 * 
******/
