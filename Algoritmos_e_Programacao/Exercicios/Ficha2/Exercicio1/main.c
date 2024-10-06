/*
Faça o algoritmo de um programa que leia um número inteiro positivo e calcule todos os seus
múltiplos inferiores a 100. Implemente o algoritmo em linguagem C.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned int num = 0;

    printf("Número inteiro positivo: ");
    scanf("%i", &num);

    for (int i = 1; i <= 100; i++)
        if (num % i == 0) printf("O número %i é múltiplo de %i\n", i, num);

    return 0;
}