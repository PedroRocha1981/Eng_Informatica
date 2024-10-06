/*
Elabore um programa que calcule o valor do seguinte somatório: n números de 2^i/i! fatorial (3! = 3 * 2 * 1) ou n! = n.(n-1);
*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num = 0;
    double soma = 0;
    long int fat = 1;

    printf("Número de valores a somar: ");
    scanf("%i", &num);

    for (int i=1; i<= num; i++){
        fat *= i;
        soma += pow(2, i) / fat;
    }

    printf("\nSoma de fatoriais de 1 a %i números é %0.2lf\n", num, soma);

    return 0;
}