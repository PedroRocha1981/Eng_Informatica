/*
No século I d.C. os números naturais dividiam-se em três categorias:
REDUZIDOS: os superiores à soma dos seus divisores;
ABUNDANTES: os inferiores à soma dos seus divisores;
PERFEITOS: os que são iguais à soma dos seus divisores.
NOTA: Nesta definição exclui-se o próprio número do conjunto dos seus divisores.
Escreva uma função que liste os inteiros entre a e b, a<b, classificando-os de acordo com esse
critério, e que escreva também o total de cada uma das categorias.
Crie um main() eu permita testar a função criada.
 * */

#include <stdio.h>
#include <locale.h>

char categoria (int n);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int a = 0, b = 0;
	
	do{
		printf("Insira o número menor inteiro diferente de 0: ");
		scanf("%d", &a);
		printf("Insira o número maior inteiro diferente de 0: ");
		scanf("%d", &b);
		printf("\n");
		
		if (a >= b) printf("O segundo número deve ser superior ao primeiro!!!\n");
	}while(a >= b); //a tem que ser menor que b para continuar
	
	if (b-a <= 1){
		printf("A diferença entre os valores tem que ser superior a 1 (ex: 1 - 3 mínimo)\n");
	}else{
		//vai percorrer a lista de números inteiros entre ambos os valores inseridos, sem contar com os mesmos
		for (int i = a + 1; i < b; ++i){
			printf("O número %d é um número inteiro ", i);
			switch(categoria(i)){
				case 'P':
					printf("PERFEITO");
					break;
				case 'R':
					printf("REDUZIDO");
					break;
				case 'A':
					printf("ABUNDANTE");
					break;
			}
			printf("\n");
		}
	}
	
	printf("\n"); //adiciona uma linha em branco
	
	return 0;
}

char categoria (int n){
	int soma = 0;
	
	for (int i = 1; i < n; i++)
		if ((n % i) == 0)
			soma += i; //se número for divisível (resto 0) por i, acrescenta a soma

	//o número é perfeito se a soma dos seus divisores for = ao número
	if (soma == n) {
		return 'P'; //é perfeito
	}else if (soma < n){
		return 'R'; //reduzido
	}else return 'A'; //abundante
}
