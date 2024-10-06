/*
Escreva um programa que coloque no ecrã meia árvore de Natal com asteriscos. O número de
ramos deverá ser indicado pelo utilizador.
Exemplos com três e quatro ramos:
    *
*   **
**  ***
*** ****
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int nr_ramos = 0;

    printf("Qual o número de ramos da árvore? ");
    scanf("%i", &nr_ramos);

    printf("\n");

    for (int i = 1; i <= nr_ramos; i++){ //percorre as várias linhas
        for (int j = 1; j <= i; j++) //nr de asteriscos para cada linha
            printf("*");
        printf("\n");
    }

    printf("\n");

    return 0;
}