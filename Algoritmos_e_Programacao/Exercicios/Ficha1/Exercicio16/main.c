/*
Escreva um programa em linguagem C que leia um número inteiro e o escreva duas vezes no
monitor, mas formatando a sua saída de dois modos diferentes:
a. reservando 8 espaços para a sua escrita
b. reservando 8 espaços para a sua escrita, mas alinhando-o à esquerda
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num = 0;

    printf("Número inteiro: ");
    scanf("%d", &num);

    printf("8 espaços %+8d", num);
    printf("\n8 espaços alinhado à esquerda %-+8d\n", num);

    return 0;
}