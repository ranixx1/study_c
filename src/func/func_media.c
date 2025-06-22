#include <cs50.h>
#include <stdio.h>

int media_2n( int n1 , int n2);


int main(void)
{
    int n1 = get_int ("Digite um número: ");
    int n2 = get_int ("Digite um número: ");
    printf("A média é: %i\n", media_2n(n1,n2));
}

int media_2n( int n1, int n2)
{
    int media = (n1 +n2) /2;
    return media;
}