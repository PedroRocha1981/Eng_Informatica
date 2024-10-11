/*
Escreva um programa para calcular a data da Páscoa de um ano indicado pelo utilizador,
permitindo-lhe repetir o cálculo enquanto ele pretender.
*/

/*
Faixa de anos 	X 	Y
1582 	1699 	22 	2
1700 	1799 	23 	3
1800 	1899 	23 	4
1900 	2099 	24 	5
2100 	2199 	24 	6
2200 	2299 	25 	7 
*/

#include <stdio.h>
#include <locale.h>

enum FAIXA_1582_1699 {
    X_1582_1699 = 22,
    Y_1582_1699 = 2
};
enum FAIXA_1700_1799 {
    X_1700_1799 = 23,
    Y_1700_1799 = 3
};
enum FAIXA_1800_1899 {
    X_1800_1899 = 23,
    Y_1800_1899 = 4
};
enum FAIXA_1900_2099 {
    X_1900_2099 = 24,
    Y_1900_2099 = 5
};
enum FAIXA_2100_2199 {
    X_2100_2199 = 24,
    Y_2100_2199 = 6
};
enum FAIXA_2200_2299 {
    X_2200_2299 = 25,
    Y_2200_2299 = 7
};


int main(){
    setlocale(LC_ALL, "Portuguese");

    char escolha = ' ';

    do{
        //escreve menu
        printf("\nA- Calcular dia de páscoa para ano;\n");
        printf("Q- Sair.\n\n");
        printf("Escolha: ");
        scanf("%c", &escolha);

        if (escolha == 'A' || escolha == 'a'){ //vai pedir o ano a calcular ao utilizador
            unsigned int ano = 0; //cria variável para o ano
            int a = 0, b = 0, c = 0, d = 0, e = 0; //variáveis para calcular o dia e o mês
            int range = 0; //variável para ver a gama de anos
            
            //pede ano ao utilizador
            printf("\nQual o ano a calcular? ");
            scanf("%ud", &ano);

            //calcula a gama de anos
            if (ano >= 1582 && ano <= 1699){
                range = 1;
            }else if (ano >= 1700 && ano <= 1799){
                range = 2;
            }else if (ano >= 1800 && ano <= 1899){
                range = 3;
            }else if (ano >= 1900 && ano <= 2099){
                range = 4;
            }else if (ano >= 2100 && ano <= 2199){
                range = 5;
            }else if (ano >= 2200 && ano <= 2299){
                range = 6;
            }

            //calcular o domingo de Páscoa:
            /*
            a = ANO MOD 19
            b = ANO MOD 4
            c = ANO MOD 7
            d = ((19*a)+X)MOD 30
            e = ((2*b)+(4*c)+(6*d)+Y) MOD 7
            se: (d+e)<10 então o dia = (d+e+22) e mês=Março
            senão: dia=(d+e-9) e mês=Abril
            */
            
            if (range > 0){ //apenas calcula se a gama do ano está entre
                a = ano % 19;
                b = ano & 4;
                c = ano % 7;

                switch (range)
                {
                case 1:
                    d = ((19*a)+X_1582_1699) % 30;
                    e = ((2*b)+(4*c)+(6*d)+Y_1582_1699) % 7;
                    break;

                case 2:
                    d = ((19*a)+X_1700_1799) % 30;
                    e = ((2*b)+(4*c)+(6*d)+Y_1700_1799) % 7;
                    break;

                case 3:
                    d = ((19*a)+X_1800_1899) % 30;
                    e = ((2*b)+(4*c)+(6*d)+Y_1800_1899) % 7;
                    break;

                case 4:
                    d = ((19*a)+X_1900_2099) % 30;
                    e = ((2*b)+(4*c)+(6*d)+Y_1900_2099) % 7;
                    break;

                case 5:
                    d = ((19*a)+X_2100_2199) % 30;
                    e = ((2*b)+(4*c)+(6*d)+Y_2100_2199) % 7;
                    break;

                case 7:
                    d = ((19*a)+X_2200_2299) % 30;
                    e = ((2*b)+(4*c)+(6*d)+Y_2200_2299) % 7;
                    break;
                
                default:
                    break;
                }

                printf("\nA Páscoa realizar-se-á a ");

                if ((d + e) < 10){
                    printf("%d de Março de %d\n", (d + e + 22), ano);
                }else printf("%d de Abril de %d\n", (d + e - 9), ano);
            }else{
                printf("\nTem que inserir um ano entre 1582 e 2299.\n");
            }
        }
    }while (escolha != 'q' && escolha != 'Q');

    printf("\n");
    return 0;
}