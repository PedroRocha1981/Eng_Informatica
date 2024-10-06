/*
Elabore um algoritmo e implemente-o para calcular o somatório de i! fatorial (3! = 3 * 2 * 1) ou n! = n.(n-1); 
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num = 0;
    long int soma = 0;
    long int fat = 1;

    printf("Número de valores a somar: ");
    scanf("%i", &num);

    for (int i=1; i<= num; i++){
        fat *= i;
        soma += fat;
    }

    printf("\nSoma de fatoriais de 1 a %i números é %li\n", num, soma);

    return 0;
}