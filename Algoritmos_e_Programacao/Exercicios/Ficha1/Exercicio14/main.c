/*
Modifique o programa anterior de modo a usar o formato 12 horas. Por exemplo, se o número
lido for 515 deve ser mostrado 8:35 a.m., se o número for 1335 deve ser mostrado 10:15 p.m.
*/

#include <stdio.h>

int main(){
    int minutos = 0, horas = 0;
    char periodo;

    printf("Quantos minutos decorridos? ");
    scanf("%d", &minutos);

    horas = minutos / 60;

    if (horas < 12) periodo = 'a';
    else{
        horas -= 12;
        periodo = 'p';
    }

    printf("\nSão %02d:%02d %c.m.\n", horas, minutos%60, periodo);

    return 0;
}