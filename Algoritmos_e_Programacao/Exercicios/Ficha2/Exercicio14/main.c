/*
Crie uma cópia do programa elaborado em resposta ao exercício anterior, e altera-a, para que
calcule a soma da seguinte série de N termos:
1 - 1/2 + 2/4 - 3/8 + 4/16 - 5/32 + …
*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned short n_termos = 0;
    float sinal = -1;
    double soma = 0;

    printf("Quantos termos? ");
    scanf("%hu", &n_termos);

    if (n_termos > 0){
        soma = 1;
        for (int i = 1; i < n_termos; i++){
                soma += sinal * (i/pow(2, i));
                //printf("\n%lf", (i/pow(2, i)));
                sinal *= -1;
            }
    }else printf("\nNúmero de termos tem que ser pelo menos 1!");

    printf("\nA soma total é de %0.2lf\n", soma);

    return 0;
}