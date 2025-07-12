#include <cs50.h>
#include <stdio.h>


int main(void)
{
    double a = get_double("Digite um valor: ");
    double b = get_double("Digite um segundo valor: ");
    double media = (a+b)/2;
    printf("A média aritmética é: %.5f\n", media);
}

