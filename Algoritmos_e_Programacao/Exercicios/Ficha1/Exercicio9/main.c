/*
Elabore um programa que leia dois números inteiros e calcule (apresentando os resultados no
monitor): a soma, a divisão inteira, o resto da divisão inteira e o produto.
*/

#include <stdio.h>

int main(){
    int num1 = 0, num2 = 0;

    printf("Insira um número inteiro: ");
    scanf("%d", &num1);

    printf("\nInsira outro número inteiro: ");
    scanf("%d", &num2);

    printf("\nA soma é %d", num1 + num2);
    printf("\nA divisão inteira é %d", num1 / num2);
    printf("\nO resto da divisão é %d", num1 % num2);
    printf("\nO produto é %d", num1 * num2);

    return 0;
}