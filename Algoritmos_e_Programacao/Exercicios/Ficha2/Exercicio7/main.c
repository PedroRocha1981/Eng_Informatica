/*
Elabore o algoritmo e crie o respetivo programa que calcule a soma dos N primeiros números
inteiros positivos, escrevendo em cada iteração o total acumulado.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num = 0;

    printf("Insira número inteiro positivo: ");
    scanf("%i", &num);

    if (num>0){
        for (int i = 1, soma = 0; i < num; i++) printf("\nSoma atual é: %i", (soma += i));
    }else printf("\nO número tem que ser inteiro positivo, acima de 0!\n");

    printf("\n");
    return 0;
}