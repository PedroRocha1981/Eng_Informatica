/*
 *Calcular a área e o comprimento da diagonal de um retângulo definido através dois pontos,
correspondentes aos vértices opostos da diagonal. Cada ponto é definido através de uma
estrutura composta por duas coordenadas x e y.
 * 
 * 
 * */

#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef struct ponto{
	int X, Y;
} Ponto;

typedef struct rect{
	Ponto left;
	Ponto right;
} Retangulo;

//prototipos
void setPonto(int x, int y, Ponto *point);
void lerCoordenada(char *str, Ponto *pointer);
void apresentaCoordenada(Ponto point);
int alturaRetangulo(Retangulo ret);
int larguraRetangulo(Retangulo ret);
int areaRetangulo(Retangulo ret);
double hipotenusa(Retangulo ret);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Retangulo ret;
	
	lerCoordenada("Ponto Esquerdo", &ret.left);
	lerCoordenada("Ponto Direito", &ret.right);
	
	//mostra as coordenadas lidas
	printf("\nO seu retângulo tem as coordenadas de ");
	apresentaCoordenada(ret.left);
	printf(" a ");
	apresentaCoordenada(ret.right);
	
	printf("\nO seu retângulo tem %d de largura e %d de altura!", larguraRetangulo(ret), alturaRetangulo(ret));
	
	printf("\nA área do Retângulo é de %d!", areaRetangulo(ret));
	printf("\nA distância entre ambos os vértices do retângulo é %0.2lf!", hipotenusa(ret));
	
	printf("\n");
	return 0;
}

/*
 * ZONA DE FUNÇÕES
 * 
*/
void setPonto(int x, int y, Ponto *point){
	point->X = x;
	point->Y = y;
}

void lerCoordenada(char *str, Ponto *pointer){	
	printf("\nCoordenada (X Y) para canto %s: ", str);
	scanf("%d %d", &pointer->X, &pointer->Y);
}

void apresentaCoordenada(Ponto point){
	printf("(%d, %d)", point.X, point.Y);
}

int alturaRetangulo(Retangulo ret){
	if (ret.right.Y > ret.left.Y) return ret.right.Y - ret.left.Y;
	
	return ret.left.Y - ret.right.Y;
}

int larguraRetangulo(Retangulo ret){
	if (ret.right.X > ret.left.X) return ret.right.X - ret.left.X;
	
	return ret.left.X - ret.right.X;
}

int areaRetangulo(Retangulo ret){
	return larguraRetangulo(ret) * alturaRetangulo(ret);
}

double hipotenusa(Retangulo ret){
	//raiz quadrada da soma dos catetos ao quadrado
	
	return sqrt(pow(alturaRetangulo(ret), 2) + pow(larguraRetangulo(ret), 2));
}
