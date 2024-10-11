/*
Escreva um programa que leia dois números a e b (inteiros) e verifique se a é múltiplo de b ou se b
é múltiplo de a.

Pedro Rocha 30887
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int a = 0, b = 0;

    //pedir os 2 números inteiros
    printf("Insira o primeiro número inteiro: ");
    scanf("%d", &a);

    printf("\nInsira o segundo número inteiro: ");
    scanf("%d", &b);

    //verifica o módulo de a por b e depois de b por a. 0 significa que é múltiplo pois dá um valor inteiro no coeficiente e resto 0
    
    //verifica se a é múltiplo de b
    if ((a % b) == 0) printf("\na é múltiplo de b\n");
    else printf("\na não é múltiplo de b\n");

    //verifica se a é múltiplo de b
    if ((b % a) == 0) printf("\nb é múltiplo de a\n");
    else printf("\nb não é múltiplo de a\n");

    return 0;
}