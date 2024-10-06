/*
Escreva um programa em C que leia um número inteiro positivo N e calcule o maior número par P
tal que a soma de todos os números pares até P seja inferior a N. Por exemplo, se for dado o valor
57 para N então o resultado será P=14 pois 2 + 4 + 6 + 8 + 10 + 12 + 14 = 56 < 57 e
2 + 4 + 6 + 8 + 10 + 12 + 14 + 16 >= 57.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Poruguese");

    int num = 0, p = 0, soma = 0;

    printf("Número: ");
    scanf("%i", &num);

    for (int i = 0; (i < num) && (soma + i < num); i++){
        if (i % 2 == 0) {
            soma += i;
            p = i;
        }
    }

    printf("\nA soma dos valores pares até %i é : %i e o número par maior é: %i\n", num, soma, p);

    return 0;
}