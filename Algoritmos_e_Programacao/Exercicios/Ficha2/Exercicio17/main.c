/*
Elabore um programa para cálculo de 𝑎^b, sendo a um número real e b um número inteiro
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    float a = 0;
    int b = 0;
    double resultado = 1;

    printf("Insira decimal a: ");
    scanf("%f", &a);
    printf("\nInsira inteiro b: ");
    scanf("%i", &b);

    if (b >0 ){
        for (int i = 1; i <= b ; i++) {
            resultado = resultado * a;
            //printf("\n%0.2lf", resultado);
        }
    }
    
    printf("\nO número %0.2f elevado a %d é %0.2lf", a, b, resultado);

    printf("\n");
    return 0;
}