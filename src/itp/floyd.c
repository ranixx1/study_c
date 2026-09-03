#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n - 1; i++)
    {
        printf("\n");
        int contador = 0;
        for (int j = 0; j <= i; j++)
        {
            contador += 1;
            printf("%d ", contador);
        }
    }
}