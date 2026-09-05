#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    char l;
    scanf(" %c", &l); 

    // O tamanho da matriz é n - 1
    int tamanho = n - 1;

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i == j || i + j == tamanho - 1)
            {
                printf("%c", l);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}