/*
Modifique o programa da alínea anterior de modo a calcular a tabuada de todos os números de 2
a 10, fazendo uma pausa depois de escrever cada uma delas
*/

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned int num = 0;

    for (num = 2; num <= 10; num++){
        for (int i = 1; i <= 10; i++) printf("\n%i x %i = %i",num, i, num*i);
        getchar();
    }

    printf("\n");

    return 0;
}