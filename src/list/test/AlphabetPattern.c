#include <stdio.h>

int main()
{
    int i, j;
    int linhas = 5;

    for (i = 0; i < linhas; i++)
    {
        char letra = 'A';

        for (j = 0; j <= i; j++)
        {
            printf("%c ", letra);
            letra++;

            printf("\n");
        }

        return 0;
    }
}