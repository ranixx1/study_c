#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("Digite um número: ");
    int soma = 0;
    for(int i=1;i<=n;i++)
    {
        soma=soma+i;
    }
    printf("A soma de 1 ate %d é: %d\n", n, soma);

    return 0;
}