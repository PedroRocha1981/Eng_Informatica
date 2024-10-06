#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main(){
    setlocale(LC_ALL, "Portguese");

    printf("Tipo char: %i\n", sizeof(char));
    printf("Tipo bool: %i\n", sizeof(bool));
    printf("Tipo short: %i\n", sizeof(short));
    printf("Tipo int: %i\n", sizeof(int));
    printf("Tipo long int: %i\n", sizeof(long int));
    printf("Tipo unsigned int: %i\n", sizeof(unsigned int));
    printf("Tipo float: %i\n", sizeof(float));
    printf("Tipo double: %i\n", sizeof(double));
    printf("Tipo long double: %i\n", sizeof(long double));

    return 0;
}