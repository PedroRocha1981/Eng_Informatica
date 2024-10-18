/*
Escreva as seguintes funções sobre o tipo char:
Função Devolve
a) int isDigit(char c) Verdade quando c é um dígito e Falso c.c.
b) int isAlpha(char c) Verdade quando c é uma letra e Falso c.c.
c) int isAlNum(char c) Verdade quando c é um carácter alfanumérico e Falso c.c.
d) char toLower(char c) Devolve c transformado na minúscula correspondente
e) char toUpper(char c) Devolve c transformado na maiúscula correspondente
 * */

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

//prototipos das funções utilizadas

int isDigit(char c);
int isAlpha(char c);
int isAlNum(char c);
char toLower(char c);
char toUpper(char c);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	char ch = ' ';
	
	printf("Insira um caractere: ");
	ch = (char)getchar();
	
	printf("\nO caractere '%c' %s um dígito!\n", ch, (isDigit(ch) == 0) ? "não é": "é");
	printf("O caractere '%c' %s uma letra!\n", ch, (isAlpha(ch) == 0) ? "não é": "é");
	printf("O caractere '%c' %s alfanumérico!\n", ch, (isAlNum(ch) == 0) ? "não é": "é");
	printf("O caractere '%c' em minúscula fica '%c'!\n", ch, toLower(ch));
	printf("O caractere '%c' em maiúscula fica '%c'!\n", ch, toUpper(ch));
	
	printf("\n"); //adiciona uma linha em branco
	
	return 0;
}

/*
 * FUNÇÕES PRETENDIDAS
 * */

//Verdade quando c é um dígito e Falso c.c. 
int isDigit(char c){
	return isdigit((int)c);
}

//Verdade quando c é uma letra e Falso c.c.
int isAlpha(char c){
	return isalpha((int)c);
}

//Verdade quando c é um carácter alfanumérico e Falso c.c.
int isAlNum(char c){
	return isalnum((int)c);
}

//Devolve c transformado na minúscula correspondente
char toLower(char c){
	return tolower((int)c);
}

//Devolve c transformado na maiúscula correspondente
char toUpper(char c){
	return toupper((int)c);
}
