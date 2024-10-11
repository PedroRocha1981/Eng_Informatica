/*
Considere as seguintes correspondências entre unidades de medida:

x cm -> y pol y = x / 2.54
x Kg -> y lbs y = x / 0.4536
x l -> y gal y = x / 3.785
xºC -> yºF y = 1.8 x + 32

Elabore um algoritmo e implemente o programa que permita converter um valor de uma das
unidades para outra.
*/

#include <stdio.h>
#include <stdbool.h>

enum tipoUni {
    CM,
    POL,
    KG,
    LBS,
    LT,
    GAL,
    C,
    F
};

double retornaMedida(double valor, enum tipoUni uni){
    if (uni == CM){ //cm para pol
        return valor / 2.54;
    }else{
        return valor * 2.54;
    }
}

double retornaPeso(double valor, enum tipoUni uni){
    if (uni == KG){ //kg para lbs
        return valor / 0.4536;
    }else{
        return valor * 0.4536;
    }
}

double retornaLiquido(double valor, enum tipoUni uni){
    if (uni == LT){ //Lt para gal
        return valor / 3.785;
    }else{
        return valor * 3.785;
    }
}

double retornaTemperatura(double valor, enum tipoUni uni){
    if (uni == C){ //C para F 1.8 x + 32
        return 1.8 * valor + 32;
    }else{
        return (valor - 32) / 1.8;
    }
}

void desenhaMenu(){
    printf("\n\n 1- Converter Cms para Pol;");
    printf("\n 2- Converter Pol para Cms;");
    printf("\n 3- Converter Kg para Lbs;");
    printf("\n 4- Converter Lbs para Kgs;");
    printf("\n 5- Converter Lt para Gal;");
    printf("\n 6- Converter Gal para Lt;");
    printf("\n 7- Converter ºC para ºF;");
    printf("\n 8- Converter ºF para ºC;");
    printf("\n q- Sair;");
    printf("\n\nEscolha: ");
}

double getValor(){
    double val = 0;
    printf("\nValor: ");
    scanf("%lf", &val);
    return val;
}

void apresentaResultado(double valor){
    printf("\nO valor é %0.2lf\n", valor);
}

int main(){
    char escolha = ' ';
    bool quit = false;

    do{
        if (escolha== ' ') desenhaMenu();
        scanf("%c", &escolha);

        switch (escolha)
        {
            case '1':
                apresentaResultado(
                    retornaMedida(
                        getValor(), 
                        CM));
                escolha = ' ';
                break;
            case '2':
                apresentaResultado(
                    retornaMedida(
                        getValor(), 
                        POL));
                escolha = ' ';
                break;
            case '3':
                apresentaResultado(
                    retornaPeso(
                        getValor(), 
                        KG));
                escolha = ' ';
                break;
            case '4':
                apresentaResultado(
                    retornaPeso(
                        getValor(), 
                        LBS));
                escolha = ' ';
                break;
            case '5': //Lt para Gal
                apresentaResultado(
                    retornaLiquido(
                        getValor(), 
                        LT));
                escolha = ' ';
                break;
            case '6':
                apresentaResultado(
                    retornaLiquido(
                        getValor(), 
                        GAL));
                escolha = ' ';
                break;
            case '7': //ºC para ºF
                apresentaResultado(
                    retornaTemperatura(
                        getValor(), 
                        C));
                escolha = ' ';
                break;
            case '8':
                apresentaResultado(
                    retornaMedida(
                        getValor(), 
                        F));
                escolha = ' ';
                break;
            case 'q':
            case 'Q':
                printf("\nObrigado!\n");
                quit = true;
                break;
            default:
                break;
        }
    }while (!quit);
    
    return 0;
}