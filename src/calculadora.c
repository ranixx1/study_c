#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int numero_1 = get_int("Digite um número: ");
    int numero_2 = get_int("Digite outro número: ");

    printf("1 - SOMA\n");
    printf("2 - SUBTRAÇÃO\n");
    printf("3 - MULTIPLICAÇÃO\n");
    printf("4 - DIVISÃO\n");

    char opcoes = get_char("Digite a operação que deseja realizar: ");

    if (opcoes == '1')
    {
        printf("Resultado: %i\n", numero_1 + numero_2);
    }
    else if (opcoes == '2')
    {
        printf("Resultado: %i\n", numero_1 - numero_2);
    }
    else if (opcoes == '3')
    {
        printf("Resultado: %i\n", numero_1 * numero_2);
    }
    else if (opcoes == '4')
    {
        if (numero_2 != 0)
        {
            printf("Resultado: %.2f\n", (float) numero_1 / numero_2);
        }
        else
        {
            printf("Erro: divisão por zero não é permitida.\n");
        }
    }
    else
    {
        printf("Opção inválida!\n");
    }
}
