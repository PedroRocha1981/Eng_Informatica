/*
Escreva uma função, utilizando ponteiros, que, dadas duas string's, str1 e str2, como parâmetros
de entrada faça a sua concatenação, devolvendo a string resultante em str1. Por exemplo, se str1
for "Aula" e str2 for "pratica" a função deverá devolver "Aulapratica" em str1.
 * 
 * */

#include <stdio.h>
#include <locale.h>


#define MAX 256 //número máximo de caracteres na junção de strings
#define MAX_STR 128 //máximo caracteres para uma string


void concatenarStr(char str1[], char str2[]){
	int i;
	for (i = 0; str1[i] != '\0'; ++i); //vai detetar em qe posição está o caracter nulo '\0'
	
	for (int j = 0; str2[j] != '\0'; ++j, ++i)
		str1[i] = str2[j];
}

int main()
{
	char str1[MAX_STR], str2[MAX_STR];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\nInsira frase1: ");
	gets(str1);
	printf("\nInsira frase2: ");
	gets(str2);
	
	concatenarStr(str1, str2);
	
	printf("\nA junção da primeira frase com a segunda:\n");
	puts(str1);
	
	printf("\n");
	
	return 0;
}


/*****
 * 
 * FUNÇÕES
 * 
******/
