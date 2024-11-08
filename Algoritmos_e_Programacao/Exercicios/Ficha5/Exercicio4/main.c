/*
 Elabore um programa que permita armazenar em memória a informação relativa a um novo livro
que chega a uma biblioteca. Considere que para cada livro deve ser guardada a seguinte
informação:
- título (máximo 30 caracteres);
- autor (máximo 30 caracteres);
- área (máximo 20 caracteres);
- ano.
O programa deve permitir a inserção de novos livros, bem como listar e retirar livros da lista.
 * 
 * 
 * */

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>

typedef struct livro{
	char titulo[30], autor[30], area[20];
	int ano;
} Livro;



//prototipos
void desenhaMenu();
Livro lerLivro();
void mostraLivro(Livro l);
void removeLivro(Livro *l, int indice, int n_livros);
void copiaLivro(Livro *destino, Livro origem);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Livro *livros;
	int n_livros = 0;
	char op = ' ';
	short quit = 0;
	
	livros = NULL;
	
	do{
		if (op == ' '){
			desenhaMenu();
			scanf(" %c", &op);
		}
		
		switch(op){
			case '1':{
					Livro l;
					
					l = lerLivro();
					
					if (n_livros == 0){ //vai alocar 1 espaço
						livros = (Livro *)malloc(sizeof(Livro));
					}else{ // vai acrescentar à lista
						livros = (Livro *)realloc(livros, (n_livros + 1) * sizeof(Livro));
					}
					
					n_livros++;
					
					strcpy(livros[n_livros-1].titulo, l.titulo);
					strcpy(livros[n_livros-1].autor, l.autor);
					strcpy(livros[n_livros-1].area, l.area);
					livros[n_livros-1].ano = l.ano;
				}
				break;
			case '2':
				if (n_livros > 0)
					for (int i = 0; i < n_livros; ++i)
						mostraLivro(livros[i]);
				break;
			case '3':
				if (n_livros > 0){
					int n = 0;
					
					for (int i = 0; i < n_livros; ++i){
						printf("\nIndice %d -> ", i+1);
						mostraLivro(livros[i]);
					}
					printf("\nQual o livro a remover? ");
					scanf(" %d", &n);
					
					removeLivro(livros, n-1, n_livros);
					
					n_livros--;
				}
				break;
			case 'q':
			case 'Q':
				quit = 1;
				break;
		}
		
		op = ' ';
	}while (quit == 0);
	
	
	free(livros);
	
	printf("\n");
	return 0;
}

/*
 * ZONA DE FUNÇÕES
 * 
*/
void copiaLivro(Livro *destino, Livro origem){
	strcpy(destino->titulo, origem.titulo);
	strcpy(destino->autor, origem.autor);
	strcpy(destino->area, origem.area);
	destino->ano = origem.ano;
}

void removeLivro(Livro *l, int indice, int n_livros){
	Livro temp;
	
	copiaLivro(&temp, l[indice-1]);
	
	for (int i = 1; i < n_livros; ++i){
		copiaLivro(&temp, l[i-1]);
		copiaLivro(&l[i-1], l[i]);
		copiaLivro(&l[i], temp);
	}

	
	l = (Livro *)realloc(l, (n_livros - 1) * sizeof(Livro));
}


void mostraLivro(Livro l){
	printf("\nTítulo: %s; Autor: %s; Área: %s; Ano: %d", l.titulo, l.autor, l.area, l.ano);
}

Livro lerLivro(){
	Livro l;
	
	printf("\nTítulo: ");
	scanf(" %s", l.titulo);
	printf("\nAutor: ");
	scanf(" %s", l.autor);
	printf("\nÁrea: ");
	scanf(" %s", l.area);
	printf("\nAno: ");
	scanf(" %d", &l.ano);
	
	return l;
}

void desenhaMenu(){
	printf("\n1- Inserir Livro");
	printf("\n2- Listar Livros");
	printf("\n3- Retirar livro");
	printf("\nq- Sair");
	printf("\nOpção: ");
}
