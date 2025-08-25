#include <stdio.h>
#include <cs50.h>

int main(void)
{
    double nota1 = get_double("nota 1:");
    double nota2 = get_double("nota 2:");
    int peso1 = get_int("peso 1: ");
    int peso2 = get_int("peso 2: ");

    double media = (nota1*peso1 + nota2*peso2)/(peso1+peso2);

    printf("A média ponderada é: %.2f\n", media);
    return 0;
}