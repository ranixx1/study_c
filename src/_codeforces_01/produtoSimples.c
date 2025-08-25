#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int a = get_int("Digite um valor para a:");
    int b = get_int("Digite um valor para b:");
    int z = a*b;
    printf("O resultado da multiplicação é: %i \n", z);

    return 0;
}


