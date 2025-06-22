#include <cs50.h>
#include <stdio.h>

int main(void){
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
    int soma = 0;
        for (int i = 0; i < tamanho; i++)
        {
            soma += lista_do_usuario[i];
        }
        printf("A soma dos elementos da sua lista é: %d\n", soma);

        return 0;
    }