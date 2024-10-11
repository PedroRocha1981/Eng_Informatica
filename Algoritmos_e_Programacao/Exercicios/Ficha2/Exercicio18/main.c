/*
Elabore um programa que calcule a média de um conjunto de valores reais positivos, considerando
os seguintes casos:
    a) O número de parcelas, n, deve ser previamente pedido ao utilizador.
    b) O programa deve pedir continuamente números reais e parar quando for introduzido um
    número negativo, calculando depois a média dos valores introduzidos (exceto o negativo).
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int qtd_numeros = 0;
    long double soma = 0;
    double num = 0;

    printf("MÉDIA PARA UMA PARCELA DE NÚMEROS REAIS:\n\n");
    
    do{
        printf("\nQuantas parcelas vai inserir para o cálculo? ");
        scanf("%d", &qtd_numeros);
    }while(qtd_numeros <= 0); //vai pedir enquanto o número de parcelas não for positivo

    for (int i = 0; i < qtd_numeros; i++){
        printf("\nNúmero real a adicionar para a média? ");
        scanf("%lf", &num);
        soma += num;
    }
    printf("\n\nA média dos %d números inseridos é %0.2Lf\n", qtd_numeros, (soma / qtd_numeros));

    //reinicia as variáveis
    qtd_numeros = 0;
    soma = 0;
    num = 0;

    printf("\n\nMÉDIA PARA NÚMEROS REAIS POSITIVOS (NEGATIVO IRÁ TERMINAR!):\n\n");
    do{
        printf("\nInsira um número real positivo: ");
        scanf("%lf", &num);

        qtd_numeros++;
        soma += num;
    }while (num >= 0);
    printf("\n\nA média dos %d números é %0.2Lf\n\n", qtd_numeros, (soma / qtd_numeros));

    printf("\n");
    return 0;
}