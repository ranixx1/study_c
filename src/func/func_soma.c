#include <stdio.h>
#include <cs50.h>

void soma(int n1, int n2);

int main(void)
{
    int n1 = get_int ("digite um numero:\n");
    int n2 = get_int ("digite um numero:\n");
    soma(n1,n2);
}

void soma( int n1, int n2)
{
    int soma = n1 + n2;
    printf("a soma é : %i\n",soma);
}
