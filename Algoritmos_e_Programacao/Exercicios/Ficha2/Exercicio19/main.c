/*
Escreva um programa em C que implemente o jogo do palpite:
Um jogador escreve um número inteiro entre 0 e 100 (o programa deve obrigar a que seja um
número dentro destes limites) e um segundo jogador tenta adivinhar esse número.
O programa deve indicar se o número dado no palpite é superior ou inferior ao número a adivinhar
e quantas tentativas foram necessárias.
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num_adivinhar = 0, num_jogador2 = 0, tentativas = 0;

    do{
        printf("Jogador 1, insira um número entre 0 e 100: ");
        scanf("%d", &num_adivinhar);
    }while (num_adivinhar < 0 || num_adivinhar > 100);

    printf("\n\n*********O Jogador 2 vai agora tentar adivinhar os número\n*********\n\n");

    do{
        printf("\nQual o numero? ");
        scanf("%d", &num_jogador2);

        if (num_jogador2 != num_adivinhar){
            if (num_jogador2 < num_adivinhar) printf("\nO número no palpite é inferior ao número a adivinhar!");
            else printf("\nO número no palpite é superior ao número a adivinhar!");
        }
        tentativas++;
    }while (num_jogador2 != num_adivinhar);

    printf("\n\nParabéns!!! Adivinhou o número do Jogador 1 em %d tentativas!\n", tentativas);

    printf("\n");
    return 0;
}