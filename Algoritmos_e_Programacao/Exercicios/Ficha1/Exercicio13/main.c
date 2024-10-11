/*
Elabore um programa que leia o número de minutos decorridos desde a meia-noite e mostre
esse número no formato horas:minutos. Por exemplo, se o número lido for 515 deve ser
mostrado 8:35, se for 1335 deve ser mostrado 22:15. Tenha em atenção que o dia tem 1440
minutos.
*/

#include <stdio.h>

int main(){
    int minutos = 0;

    printf("Quantos minutos decorridos? ");
    scanf("%d", &minutos);

    printf("\nSão %02d:%02d\n", minutos/60, minutos%60);

    return 0;
}