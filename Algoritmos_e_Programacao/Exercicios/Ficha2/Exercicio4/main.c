/*
Elabore um algoritmo que peça ao utilizador para introduzir um número entre 0 e 9 e enquanto não
for introduzido um valor válido, a leitura é repetida.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num = -1;

    do{
        printf("\nInsira um valor entre 0 e 9 inclusivé: ");
        scanf("%d", &num);
    }while (!(num >=0 && num <=9));

    return 0;
}