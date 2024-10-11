/*
Escreva uma instrução de atribuição em C para cada uma das seguintes ações:
a) A variável inteira i é incrementada uma unidade.
b) A variável lógica v é verdadeira se e só se a variável inteira x tomar o valor 8 ou o valor 80.
c) A variável inteira r toma o valor do resto da divisão de x por 2.
d) A variável lógica m é verdadeira se e só se x for múltiplo de n.
e) A variável lógica maior é verdadeira se e só se a variável x for maior que a variável y.
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int i = 0, r = 0, x = 0, n = 0, y = 0;
    bool v = false, m = false, maior = false;

    printf("Variável x :");
    scanf("%d", &x);
    printf("Variável n: ");
    scanf("%d", &n);
    printf("Variável y: ");
    scanf("%d", &y);

    i++; //a
    v = (x == 8 || x == 80) ? true : false; //b
    printf("\nVariável v é %d", v);
    r = x % 2;//c
    m = ((x * n) % 2 == 0) ? true : false; //d
    printf("\nx é múltiplo de n? %d", m);
    maior = (x > y) ? true : false;//e
    printf("\nx é maior que y? %d \n", maior);

    return 0;
}