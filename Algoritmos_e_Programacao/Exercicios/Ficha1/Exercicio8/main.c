/*
    Ficha 1 Exercício 8 - Elabore o algoritmo e implemente o programa que permita calcular a área e o perímetro das
seguintes figuras geométricas: quadrado, retângulo e círculo.

    Pedro Rocha 30887
*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

const float PI = 3.14159265359; //define constante PI, não poderá ser alterada

int main(){
    setlocale(LC_ALL, "Portuguese");

    char escolha = ' ';
    double alt = 0, larg = 0, raio = 0;

    //cria menu
    printf("Escolha uma das opções:\n");
    printf("1- Quadrado\n");
    printf("2- Retângulo\n");
    printf("3- Círculo\n");
    printf("Opção: ");
    scanf("%c", &escolha);

    //condição por escolha
    switch(escolha){
        case '1':
            printf("\nAltura? ");
            scanf("%lf", &alt);
            printf("\nA área do quadrado é %0.2lf cm2\n", pow(alt, 2));
            printf("O perímetro do quadrado é %0.2lf cm\n", alt*4);
            break;
        case '2':
            printf("\nAltura? ");
            scanf("%lf", &alt);
            printf("\nLargura? ");
            scanf("%lf", &larg);
            printf("\nA área do retângulo é %0.2lf cm2\n", alt * larg);
            printf("O perímetro do retângulo é %0.2lf cm\n", alt * 2 + larg * 2);
            break;
        case '3':
            printf("\nRaio? ");
            scanf("%lf", &raio);
            printf("\nA área do círculo é %0.2lf cm2\n", PI * pow(raio, 2));
            printf("O perímetro do círculo é %0.2lf cm\n", 2 * PI * raio);
            break;
        default:
            printf("\nOpção não existente!\n");
            break;
    }

    return 0;
}