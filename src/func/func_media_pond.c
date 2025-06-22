#include <cs50.h>
#include <stdio.h>

int media_pond(int n1,int n2,int p1,int p2);

int main(void)
{
    int n1 = get_int ("Digite a nota 1: ");
    int p1 = get_int ("Digite o peso 1: ");
    int n2 = get_int ("Digite a nota 2: ");
    int p2 = get_int ("Digite o peso 2: ");

    printf(" A média ponderada é: %i\n", media_pond(n1,n2,p1,p2));
}

int media_pond(int n1,int n2,int p1,int p2)
{
    int media_pond = (n1 * p1 + n2 * p2) / (p1 +p2);
}