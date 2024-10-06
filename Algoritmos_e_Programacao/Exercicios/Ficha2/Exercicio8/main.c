/*
Escreva um programa em C que calcule a tabuada de um número inteiro i dado pelo utilizador. A
tabuada deve aparecer no monitor no formato:
i x 1 = i
i x 2 = 2i
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned int num = 0;

    printf("Qual o número para o qual pretende a tabuada? ");
    scanf("%i", &num);

    for (int i = 1; i <= 10; i++) printf("\n%i x %i = %i",num, i, num*i);

    printf("\n");
    return 0;
}