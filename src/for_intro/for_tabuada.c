#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("Digite um número para mostrar a tabuada:");
    for (int i=0;i<=10;i++)
    {
         printf("%d x %d = %d\n", n, i, n * i);
    }
    return 0;
}