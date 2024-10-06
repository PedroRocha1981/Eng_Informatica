/*
Sendo dado o valor de N, compreendido entre 1 e 9, produza uma pirâmide de números de acordo
com o exemplo seguinte para N=3.
    1
   121
  12321
*/


#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned int num = 0;

    printf("Insira um número de 1 a 9: ");
    scanf("%i", &num);

    if (num >= 1 || num <= 9){ //verifica se número está entre os pretendidos
        //ciclo para chegar ao número pretendido
        for (int pos = 1; pos <= num; pos++){
            short white_spaces = num - pos; //numero de espaços em branco

                //mostra os espaços em branco

                if (white_spaces > 0) for(int i = 0; i < white_spaces; i++) printf(" ");

                //mostra o número no final

                for (int i = 1; i<= pos; i++) printf("%i", i);

                //mostra o inverso

                if (pos >= 1) for (int i = pos-1; i >=1; i--) printf("%i", i);

                printf("\n");
        }
    }else printf("\nO número tem qe estar entre 1 e 9 inclusivé!\n");

    printf("\n");
    return 0;
}