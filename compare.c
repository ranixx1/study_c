#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int ("Digite um valor para x: ");
    int y = get_int ("Digite um valor para y: ");

    if ( x > y)
    {
        printf("X é maior\n");
    }
    else if (y > x)
    {
        printf("y é maior");
    }
    else
    {
        printf("Iguais");
    }
}