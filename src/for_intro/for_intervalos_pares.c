#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int inicio = get_int("Digite um numero (Inicio): ");
    int fim = get_int("Digite um numero (Fim): ");

    printf("\nNumeros pares entre %d e %d:\n", inicio, fim);

    printf("[");

    int primeiro_par_impresso = 0; 

    for (int i = inicio; i <= fim; i++)
    {
        if (i % 2 == 0)
        {
            if (primeiro_par_impresso == 1)
            {
                printf(", ");
            }
            printf("%d", i);
            primeiro_par_impresso = 1; 
        }
    }
    printf("]\n");

    return 0;
}