/*
Elabore um algoritmo e implemente o programa que permita determinar o número de dias que
faltam até ao fim do mês, numa determinada data.
*/

/*
ano bissexto tem 29 dias fevereiro
30 dias :
abril 4
junho 6
setembro 9
novembro 11
o resto tem 31 dias
*/

#include <stdio.h>
#include <stdbool.h>

//verifica se o ano é bissexto
bool bissexto (int ano){
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) return true;
    else return false;
}

//retorna dias até ao fim do mês
int diasParaFimMes(int dia, int mes, int ano){
    switch (mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        //30 dias
        return 30 - dia;
        break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        //31 dias
        return 31 - dia;
        break;

    default:
        if (bissexto(ano)) return 29 - dia;
        else return 28 - dia;
    }
}

int main(){
    int dia = 0, mes = 0, ano = 0;

    printf("Insira uma data dd mm aaaa: ");
    scanf("%d %d %d", &dia, &mes, &ano);

    printf("\nFaltam %d dias para o fim do mês.", diasParaFimMes(dia, mes, ano));

    return 0;
}