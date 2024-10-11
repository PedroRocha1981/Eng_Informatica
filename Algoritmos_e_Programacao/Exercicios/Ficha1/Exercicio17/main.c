/*
Elabore um programa que leia do teclado um número real e o escreva no monitor, limitando a 3
o nº de casas decimais
*/

#include <stdio.h>

int main(){
    double num = 0.0;

    printf("Valor decimal: ");
    scanf("%lf", &num);

    printf("\nO valor inserido é %0.3lf\n", num);
    
    return 0;
}