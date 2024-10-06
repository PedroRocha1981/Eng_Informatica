/*
Escreva um programa em C que peça um número inteiro positivo e escreva todos os seus divisores,
do maior para o menor.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned int num = 0;

    printf("Número inteiro positivo: ");
    scanf("%i", &num);

    if (num >= 1){
        for (int i = num; i > 0; i--)
            if (num % i == 0) printf("\nO número %i é divisor de %i.", i, num);
    }else printf("\nO número tem que ser maior ou igual a 1!");

    printf("\n");

    return 0;
}