/*
Escreva um programa que determine as raízes reais de uma equação do 2.º grau ax2 + bx + c = 0,
em que a, b e c são pedidos ao utilizador. Não se esqueça de prever a hipótese de a equação não
ter raízes reais.
*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    double a = 0, b = 0, c = 0, delta = 0, s1 = 0, s2 = 0;

    setlocale(LC_ALL, "Portuguese");

    printf("Valores para equação ax² + bx + c = 0\nValor de a: ");
    scanf("%lf", &a);
    printf("\nValor de b: ");
    scanf("%lf", &b);
    printf("\nValor de c: ");
    scanf("%lf", &c);

    delta = pow(b, 2) - 4 * a * c;

    if (delta < 0)
        printf("\nA equação é impossível porque o delta dá número inferior a 0.");
    else if (delta == 0){ //única solução
            s1 = (-b + sqrt(delta)) / (2 * a);
            printf("\nSolução única %.2lf", s1);
        }else{ //duas soluções
            s1 = (-b + sqrt(delta)) / (2 * a);

            s2 = (-b - sqrt(delta)) / (2 * a);
            printf("\nSolução = {%.2lf, %.2lf}\n", (s1 < s2) ? s1: s2, (s1 > s2) ? s1: s2);
        }

    return 0;
}