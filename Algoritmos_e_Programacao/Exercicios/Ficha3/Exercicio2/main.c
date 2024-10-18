/*
a) Escreva as funções a seguir indicadas de modo que devolvam os resultados descritos:
Função Devolve
a) int resto (int a, int b) O resto da divisão de a por b
b) int impar (int x) Verdade se x for impar e Falso c.c.
c) int perfeito (int n) Verdade se n for “perfeito” (igual à soma dos divisores de n, inferiores a n) e
Falso c.c.
d) int primo (int n) Verdade se n for “primo” (apenas divisível por 1 e por n) e Falso c.c.
 * 
 * 
b) Crie um main() que permita testar as funções criadas nos exercícios 1 e 2.
 * */

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

//prototipos das funções utilizadas

//exercicio1
int isDigit(char c);
int isAlpha(char c);
int isAlNum(char c);
char toLower(char c);
char toUpper(char c);

//exercício 2
int resto (int a, int b);
int impar (int x);
int perfeito (int n);
int primo (int n);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	char ch = ' '; //variável para exercício 1
	int num1 = 0, num2 = 0; //variáveis para exercício 2
	
	//código referente ao exercício 1

	printf("Insira um caractere: ");
	ch = (char)getchar();
	
	printf("\nO caractere '%c' %s um dígito!\n", ch, (isDigit(ch) == 0) ? "não é": "é");
	printf("O caractere '%c' %s uma letra!\n", ch, (isAlpha(ch) == 0) ? "não é": "é");
	printf("O caractere '%c' %s alfanumérico!\n", ch, (isAlNum(ch) == 0) ? "não é": "é");
	printf("O caractere '%c' em minúscula fica '%c'!\n", ch, toLower(ch));
	printf("O caractere '%c' em maiúscula fica '%c'!\n", ch, toUpper(ch));

	/*************************************************************************************/
	
	//código referente ao exercício2
	
	printf("\n\n"); //dá algum espaço do exercício anterior
	
	printf("Insira um número inteiro: ");
	scanf("%d", &num1);
	printf("\nInsira outro número inteiro: ");
	scanf("%d", &num2);
	
	//executa as funções
	printf("\nO resto da divisão de %d por %d é %d!\n", num1, num2, resto(num1, num2));
	printf("O número %d %s ímpar!\n", num1, (impar(num1) == 0) ? "é": "não é");
	printf("O número %d %s um número perfeito!\n", num1, (perfeito(num1) == 0) ? "não é": "é");
	printf("O número %d %s um número primo!\n", num1, (primo(num1) == 0) ? "não é": "é");
	
	printf("\n"); //adiciona uma linha em branco
	
	return 0;
}

/*
 * FUNÇÕES PRETENDIDAS
 * */

/*
 * EXERCÍCIO 1
*/

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


/*
 * EXERCÍCIO 2
*/

//O resto da divisão de a por b
int resto (int a, int b){
	if (b >= 1 ) return a % b;
	else return 0; //não pode dividir por zero
}

//Verdade se x for impar e Falso c.c.
int impar (int x){
	if (x % 2 == 0) return 1;
	else return 0;
}

//Verdade se n for “perfeito” (igual à soma dos divisores de n, inferiores a n) e Falso c.c.
int perfeito (int n){
	int soma = 0;
	
	for (int i = 1; i < n; i++)
		if ((n % i) == 0)
			soma += i; //se número for divisível (resto 0) por i, acrescenta a soma

	//o número é perfeito se a soma dos seus divisores for = ao número
	if (soma == n) return 1; //é perfeito
	else return 0; //não é perfeito
}

//Verdade se n for “primo” (apenas divisível por 1 e por n) e Falso c.c.
int primo (int n){
	if (n >= 3){ //números 1 e 2 são primos, logo só vai ver para valores superiores
		for (int i = 2; i < n; i++) //percorre divisores de 2 a n-1
			if (n % i == 0) return 0; //caso seja divisível (resto 0), significa que é divisível por mais que 1 e o próprio número
	} else if (n == 1) return 0; //número 1 não é primo porque só é divisível por 1
	
	return 1; //retorna verdadeiro caso o código anterior não retorne 0
}
