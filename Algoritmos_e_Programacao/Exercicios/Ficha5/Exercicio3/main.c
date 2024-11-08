/*
 *Pretendem-se registar as notas de um máximo de 50 estudantes. Para cada estudante é
necessário registar o número, nome e a nota respetiva.
a) Elabore um programa que solicite ao utilizador N nomes, respetivos números e notas (sendo
N <=50); depois, dado o número de um estudante, mostre o respetivo nome e nota;
b) Crie um novo programa ou um novo projeto (copie e altere o anterior), mas, desta vez,
estruturando-o, usando funções e use ponteiros para aceder aos elementos do vetor.
 * 
 * 
 * */

#include <stdio.h>
#include <locale.h>
#include <malloc.h>

typedef struct aluno{
	char nome[100];
	int numero;
	float nota;
} Aluno;

const short MAX = 50;

//prototipos
void lerAluno(Aluno *al);
void mostraAluno(Aluno al);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Aluno *alunos;
	short n_alunos;
	
	//pergunta quantos alunos
	do{
		printf("\nQuantidade de alunos (máximo %d): ", MAX);
		scanf(" %hd", &n_alunos);
	}while (n_alunos <= 0 || n_alunos > MAX);
	
	//aloca memória para o vetor de alunos
	alunos = (Aluno *)malloc(n_alunos * sizeof(Aluno));
	if (alunos == NULL){
		printf("\nPrograma não foi capaz de alocar memória!!!\n");
		return 1; //sai do programa
	}
	
	//pede dados de cada aluno
	for (int i = 0; i < n_alunos; ++i){
		printf("\nAluno %d: ", i + 1);
		lerAluno(&alunos[i]);
	}
	
	//mostra os alunos e notas
	for (int i = 0; i < n_alunos; ++i)
		mostraAluno(alunos[i]);
	
	//liberta memória	
	free(alunos);
	
	printf("\n");
	return 0;
}

/*
 * ZONA DE FUNÇÕES
 * 
*/
void mostraAluno(Aluno al){
	printf("\n%d - %s teve %.2f valores", al.numero, al.nome, al.nota);
}

void lerAluno(Aluno *al){
	printf("\nNúmero do Aluno: ");
	scanf(" %d", &al->numero);
	printf("\nNome do Aluno: ");
	scanf(" %s", al->nome);
	printf("\nNota do Aluno: ");
	scanf(" %f", &al->nota);
}
