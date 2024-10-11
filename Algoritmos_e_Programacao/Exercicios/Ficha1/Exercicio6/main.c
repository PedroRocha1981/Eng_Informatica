#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL, "Portuguese"); //muda o local para Portugal
    
    char escolha = ' ';
    double c = 0, a = 0, b = 0;

    printf("Tem o valor da hipotenusa? s/n: ");
    scanf("%c", &escolha);

    if (escolha == 's' || escolha == 'S'){
        //resposta sim (S/s) vai pedir hipotenusa e um cateto e processar o outro cateto

        printf("\nQual o valor da hipotenusa? ");
        scanf("%lf", &c); //ler hipotenusa

        printf("\nQual o valor do cateto? ");
        scanf("%lf", &a); //ler cateto a

        //vai processar o valor do cateto restante
        b = sqrt(pow(c, 2) - pow(a, 2)); //função pow(x, y); significa x elevado a y, no nosso caso x ao quadrado

        printf("\nO valor do cateto restante é %0.2f", b);
    }else{
        //caso não tenha a hipotenusa, vai pedir os catetos e processar a hipotenusa

        printf("\nQual o valor do cateto a? ");
        scanf("%lf", &a); //ler cateto a

        printf("\nQual o valor do cateto b? ");
        scanf("%lf", &b); //ler cateto b

        //vai processar o valor da hipotenusa
        c = sqrt(pow(a, 2) + pow(b, 2)); 

        printf("\nO valor da hipotenusa é %0.2lf", c);       
    }

    return 0;
}