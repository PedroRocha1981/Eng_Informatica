/*
Elabore o algoritmo e implemente o programa que determine se um ano dado é comum ou
bissexto.
Note que um ano é bissexto se for divisível por 4 mas não por 100, exceto se for divisível por 400

Para determinar se um ano é um ano bissexto, siga estas etapas:

    1- Se o ano for uniformemente divisível por 4, vá para o passo 2. Caso contrário, avance para o passo 5.
    2- Se o ano for uniformemente divisível por 100, vá para o passo 3. Caso contrário, avance para o passo 4.
    3- Se o ano for uniformemente divisível por 400, vá para o passo 4. Caso contrário, avance para o passo 5.
    4- O ano é um ano bissexto (tem 366 dias).
    5- O ano não é um ano bissexto (tem 365 dias).

IF(
    OR(MOD(
        A1,400)=0,
        AND(MOD(A1,4)=0, MOD(A1,100)<>0
        )
    ),
    "Leap Year", 
    "NOT a Leap Year"
)
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int ano = 0;
    bool bissexto = false;

    printf("Qual é o ano a verificar: ");
    scanf("%d", &ano);

    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) bissexto = true;

    printf("\nO ano %d %sé bissexto.", ano, bissexto ? "" : "não ");

    return 0;
}