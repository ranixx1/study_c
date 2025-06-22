#include <cs50.h>
#include <stdio.h>

char* create_list();

int main(void)
{
    create_list();
    return 0;
}

char* create_list()
{
    int tamanho;
    do
    {
        tamanho = get_int("Quantos elementos voce quer na lista (max 10)? ");
    }
    while (tamanho <= 0 || tamanho > 10);

    int lista_do_usuario[tamanho]; 
    
    printf("\n--- Preenchendo a lista com valores do usuario ---\n");
    for (int i = 0; i < tamanho; i++)
    {
        lista_do_usuario[i] = get_int("Digite o elemento %d: ", i + 1);
    }

    printf("\n--- Sua lista ---\n");
    printf("[");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d", lista_do_usuario[i]);

        if (i < tamanho - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    return NULL; 
}