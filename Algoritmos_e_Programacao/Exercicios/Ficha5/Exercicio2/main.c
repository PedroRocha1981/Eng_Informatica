/*
 *Defina o tipo de dados Fracção (numerador/denominador) e implemente as operações de soma,
subtração, divisão e multiplicação de frações. Os numeradores, denominadores e operação são
pedidos ao utilizador.
 * 
 * 
 * */

#include <stdio.h>
#include <locale.h>

typedef struct fraccao{
	int numerador, denominador;
} Fraccao;

enum operacao {
	SOMA,
	SUBTRACAO,
	DIVISAO,
	MULTIPLICACAO
};

//prototipos
void lerFracao(Fraccao *fraction);
void desenhaMenu();
double operaFracoes(Fraccao f1, Fraccao f2, enum operacao op);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Fraccao f, f2;
	short exit = 0;
	char op = ' ';
	
	do{
		if (op == ' '){
			desenhaMenu();
			scanf(" %c", &op);
		}
		
		switch (op){
			case '1':
				lerFracao(&f);
				break;
				
			case '2':
				lerFracao(&f2);
				break;
			case '3':
				printf("\nA soma das frações é %0.2lf !", operaFracoes(f, f2, SOMA));
				break;
			case '4':
				printf("\nA soma das frações é %0.2lf !", operaFracoes(f, f2, SUBTRACAO));
				break;
			case '5':
				printf("\nA soma das frações é %0.2lf !", operaFracoes(f, f2, DIVISAO));
				break;
			case '6':
				printf("\nA soma das frações é %0.2lf !", operaFracoes(f, f2, MULTIPLICACAO));
				break;
			case 'q':
			case 'Q':
				printf("\nAté à próxima!!");
				exit = 1;
				break;
		}
		
		op = ' ';
		printf("\n");
	}while (exit == 0);
	
	printf("\n");
	return 0;
}

/*
 * ZONA DE FUNÇÕES
 * 
*/
double operaFracoes(Fraccao f1, Fraccao f2, enum operacao op){
	switch (op){
		case SOMA:
			return ((double)f1.numerador / (double)f1.denominador + (double)f2.numerador / (double)f2.denominador);
		case SUBTRACAO:
			return ((double)f1.numerador / (double)f1.denominador - (double)f2.numerador / (double)f2.denominador);
		case DIVISAO:
			return (((double)f1.numerador / (double)f1.denominador) / ((double)f2.numerador / (double)f2.denominador));
		case MULTIPLICACAO:
			return (((double)f1.numerador / (double)f1.denominador) * ((double)f2.numerador / (double)f2.denominador));
		default:
			return 0;
	}
}

void desenhaMenu(){
	printf("\n1- Definir fração 1");
	printf("\n2- Definir fração 2");
	printf("\n3- Somar frações");
	printf("\n4- Subtrair frações");
	printf("\n5- Dividir frações");
	printf("\n6- Multiplicar frações");
	printf("\nq- Sair");
	printf("\n\nOpção: ");
}

void lerFracao(Fraccao *fraction){
	printf("\nNumerador: ");
	scanf("%d", &fraction->numerador);
	printf("\nNumerador: ");
	scanf("%d", &fraction->denominador);
}
