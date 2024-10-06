/*
Faça um algoritmo para um programa que leia uma sequência de números inteiros positivos e
determine quantos números são pares e quantos são ímpares. A finalização da sequência de
números é indicada introduzindo-se um número negativo.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num = 0;

    printf("Insira valores inteiros, um valor negativo terminará o programa:\n");
    do{
        printf("\nInsira um valor inteiro para saber se é par: ");
        scanf("%i", &num);
        if (num >= 0)
            if(num % 2 == 0) printf(" -> O número é par");
            else printf(" -> O número é ímpar");
    }while (num >= 0);

    return 0;
}