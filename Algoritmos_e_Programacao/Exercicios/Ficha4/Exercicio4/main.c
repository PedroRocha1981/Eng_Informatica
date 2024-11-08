/*
 * 4 - Elabore funções, utilizando ponteiros, que:
a) Leia um vetor de n elementos inteiros (n é especificado pelo utilizador);
b) Apresente no monitor os elementos do vetor;
c) Apresente no monitor os elementos do vector pela ordem inversa;
d) Determine o máximo do vetor;
e) Determine o mínimo do vetor;
f) Determine a soma das componentes;
g) Determine a média dos elementos do vetor;
h) Determine quantos elementos do vetor são superiores à média e quantos são inferiores;
i) Duplique para outro vetor os valores lidos;
j) Intercale os dois vetores (o 2.o por ordem inversa) e disponibilize um terceiro vetor
resultante. Ex.:
vetor x = [1 3 5 7]
					=> vetor final = [1 8 3 6 5 4 7 2]
vetor y = [2 4 6 8]
 * 
 * 
 * */

#include <stdio.h>
#include <locale.h>
#include <malloc.h>

enum ORDEM {
	NORMAL,
	INVERSA
}; //ordem para apresentar o vetor

enum VALOR {
	MIN,
	MAX
};

enum OPERACAO {
	SOMA,
	MEDIA
};

enum ELEMENTOS {
	INFERIORES,
	SUPERIORES
};

//prototipos
void ler_elementos(int *vet, int n_elementos);
void apresentaVetor(int vet[], int n_elementos, enum ORDEM ord);
int valorMinMax(int *vet, int n_elementos, enum VALOR val);
double retornaSomaMedia(int *vet, int n_elementos, enum OPERACAO op);
int elementosInfSupMedia(int *vet, int n_elementos, double media, enum ELEMENTOS elem);
void duplicaVetor(int *vet, int *vet_clone, int n_elementos);
void intercalaVetores(int *vet, int *vet2, int *vet_final, int n_elementos);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n_elementos = 0;
	int *vetor, *vetor2, *vetor_final;
	double media = 0;
	
	//alínea a)
	printf("Quantos elementos vai ter o seu vetor? ");
	scanf("%d", &n_elementos);
	
	vetor = (int*)malloc(n_elementos * sizeof(int)); //aloca memória e verifica de seguida se foi alocada
	if (vetor == NULL){
		printf("\n!!!! NÃO FOI POSSÍVEL ALOCAR MEMÓRIA!!!\nO programa vai terminar!!!\n");
		return 1; //retorna falso
	}
	
	ler_elementos(vetor, n_elementos);
	
	//alínea b)
	apresentaVetor(vetor, n_elementos, NORMAL);
	
	//alínea c)
	apresentaVetor(vetor, n_elementos, INVERSA);
	
	//alínea d)
	printf("\nO valor máximo no vetor é de %d!", valorMinMax(vetor, n_elementos, MAX));
	
	//alínea e)
	printf("\nO valor mínimo no vetor é de %d!", valorMinMax(vetor, n_elementos, MIN));
	
	//alínea f)
	printf("\nA soma dos elementos é %d!", (int)retornaSomaMedia(vetor, n_elementos, SOMA));
	
	//alíena g)
	media = retornaSomaMedia(vetor, n_elementos, MEDIA);
	printf("\nA média dos elementos é %0.2lf!", media);
	
	//alínea h)
	printf("\nExistem %d elementos Superiores à média %0.2lf e %d números inferiores!", 
		elementosInfSupMedia(vetor, n_elementos, media, SUPERIORES), media,
		elementosInfSupMedia(vetor, n_elementos, media, INFERIORES));
	
	vetor2 = (int*)malloc(n_elementos * sizeof(int)); //aloca memória e verifica de seguida se foi alocada
	if (vetor2 == NULL){
		printf("\n!!!! NÃO FOI POSSÍVEL ALOCAR MEMÓRIA!!!\nO programa vai terminar!!!\n");
		return 2; //retorna falso
	}
	
	//alínea i)
	printf("\nVetor original");
	apresentaVetor(vetor, n_elementos, NORMAL);
	
	duplicaVetor(vetor, vetor2, n_elementos);
	
	printf("\nVetor duplicado");
	apresentaVetor(vetor2, n_elementos, NORMAL);
	
	vetor_final = (int*)malloc(2 * n_elementos * sizeof(int)); //aloca memória e verifica de seguida se foi alocada
	if (vetor_final == NULL){
		printf("\n!!!! NÃO FOI POSSÍVEL ALOCAR MEMÓRIA!!!\nO programa vai terminar!!!\n");
		return 3; //retorna falso
	}
	
	//alínea j)
	intercalaVetores(vetor, vetor2, vetor_final, n_elementos);
	
	printf("\nO vetor intercalado:");
	apresentaVetor(vetor_final, n_elementos * 2, NORMAL);

	free(vetor);
	free(vetor2);
	free(vetor_final);
	
	printf("\n");
	return 0;
}

/*
 * ZONA DE FUNÇÕES
 * 
*/

void ler_elementos(int *vet, int n_elementos){
	for (int i = 0; i < n_elementos; ++i){
		printf("\nValor inteiro para elemento nr %d: ", i+1);
		scanf("%d", &vet[i]);
	}
}

void apresentaVetor(int vet[], int n_elementos, enum ORDEM ord){
	printf("\nOs elementos do vetor na ordem %s são: \n", (ord == NORMAL) ? "NORMAL": "INVERSA");
	if (ord == NORMAL){
		for (int i = 0; i < n_elementos; ++i)
		printf(" %d\n", vet[i]);
	}else{
		for (int i = n_elementos - 1; i >= 0; --i)
		printf(" %d\n", vet[i]);
	}
}

int valorMinMax(int *vet, int n_elementos, enum VALOR val){
	int valor = vet[0];
	
	for (int i = 1; i < n_elementos; ++i)
		if (val == MAX){ //valor máximo
			if (vet[i] > valor) valor = vet[i];
		}else{ //valor mínimo
			if (vet[i] < valor) valor = vet[i];
		}
	
	return valor;
}

double retornaSomaMedia(int *vet, int n_elementos, enum OPERACAO op){
	int soma = 0;
	
	for (int i = 0; i < n_elementos; ++i)
		soma += vet[i];
	
	if (op == SOMA) return soma;
	
	//vai fazer a média
	
	return (double)soma / (float)n_elementos;
}

int elementosInfSupMedia(int *vet, int n_elementos, double media, enum ELEMENTOS elem){
	int num = 0;
	
	if (elem == SUPERIORES){
		for (int i = 0; i < n_elementos; ++i)
			if (vet[i] < media) num++;
	}else{
		for (int i = 0; i < n_elementos; ++i)
			if (vet[i] > media) num++;
	}
	
	return num;
}

void duplicaVetor(int *vet, int *vet_clone, int n_elementos){
	for (int i = 0; i < n_elementos; ++i)
		vet_clone[i] = vet[i];
}

void intercalaVetores(int *vet, int *vet2, int *vet_final, int n_elementos){
	//Intercale os dois vetores (o 2.o por ordem inversa) e disponibilize um terceiro vetor resultante.
	for (int i = 0, j = n_elementos - 1, n = 0; i < n_elementos && j >= 0; ++i, --j){
		vet_final[n] = vet[i];
		n++;
		vet_final[n] = vet2[j];
		n++;
	}
}
