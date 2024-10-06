/*
Escreva um programa que calcule a soma da seguinte série de N termos:
1 - 1/2 + 1/4 - 1/6 + 1/8 - 1/10 + ...
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned short n_termos = 0;
    float sinal = -1;
    double soma = 0;

    printf("Quantos termos? ");
    scanf("%i", &n_termos);

    if (n_termos > 0){
        soma = 1;
        if (n_termos > 1)
        for (int i = 2; i < n_termos*2; i +=2){
            soma += sinal * (1/(float)i);
            //printf("\n%0.2lf", sinal * (1/(float)i));
            sinal *= -1;
        }
    }else printf("\nNúmero de termos tem que ser pelo menos 1!");

    printf("\nA soma total é de %0.2lf\n", soma);

    return 0;
}