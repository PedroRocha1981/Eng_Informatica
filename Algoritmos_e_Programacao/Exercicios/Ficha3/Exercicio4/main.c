/*
Elabore funções que determinem:
a. O cubo de um número inteiro n. O número n deve ser pedido ao utilizador através de uma
função (denominada leitura) e o seu cubo deve ser calculado através de outra função (de nome
cubo).
b. Copiar a função cubo criada na alínea a., e alterá-la, criando a função exponenciação, de forma
a torná-la mais genérica: calcular x^exp. Os números x e exp devem ser solicitados ao utilizador
através da função leitura. De igual modo, x^exp deve ser calculado através da função
exponenciação.
Obs. No final, teste e corrija as funções, criando um main() para o efeito.
 * */

#include <stdio.h>
#include <locale.h>

int pedirNum();
int calculaCubo(int num);
int calculaExponencial(int num, int expoente);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int cubo_x = calculaCubo(pedirNum());
	int exp = 0;
	
	printf("\nO número pedido ao cubo (x^3) é %d\n\n", cubo_x);
	
	cubo_x = pedirNum();
	exp = pedirNum();
	printf("\nO número %d elevado a %d (%d^%d) é %d !\n", cubo_x, exp, cubo_x, exp, calculaExponencial(cubo_x, exp));
	
	printf("\n"); //adiciona uma linha em branco
	
	return 0;
}

//função que pede número ao utilizador
int pedirNum(){
	int n = 0;
	
	printf("Insira um número inteiro: ");
	scanf("%d", &n);
	
	return n;
}

int calculaCubo(int num){
	return calculaExponencial(num, 3);
}

int calculaExponencial(int num, int expoente){
	int resultado = 1;
	
	if (expoente > 0){
		for (int i = 0; i < expoente; i++)
			resultado = resultado * num;
	}
	
	return resultado;
}
