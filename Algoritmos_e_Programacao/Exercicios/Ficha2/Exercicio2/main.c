/*
 Elabore um programa que determine todos os números pares entre dois números inteiros ni e nf
(ni<nf).
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num1 = 0, num2 = 0;

    printf("Número inteiro mais pequeno: ");
    scanf("%i", &num1);
    printf("\nNúmero inteiro maior: ");
    scanf("%i", &num2);

    if (num1 < num2){
        printf("\nOs números pares entre %i e %i são:", num1, num2);

        for (int i = num1 + 1; i < num2; i++)
            if (i % 2 == 0) printf("\nO número %i é par;", i);
        
        printf("\n");
    }else printf("\n O primeiro número tem que ser inferior ao segundo número!\n");

    return 0;
}