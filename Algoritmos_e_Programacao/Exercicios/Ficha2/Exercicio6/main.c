/*
Elabore um programa que determine os n primeiros múltiplos de um número inteiro m.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num = 0;

    printf("Insira um número inteiro: ");
    scanf("%i", &num);

    if (num > 1)
        for(int i = 1; i < num; i++){
            if (num % i == 0) printf("\n%i é múltiplo de %i", i, num);
            }
    else printf("\nO número é inferior ou igual a 1\n");

    printf("\n");

    return 0;
}