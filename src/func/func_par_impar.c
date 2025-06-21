#include <cs50.h>
#include <stdio.h>

int verifica_par_impar( int n);

int main(void)
{
    int n = get_int("Digite um número qualquer:");
    verifica_par_impar(n);
}

int verifica_par_impar(int n)
{
    if (n%2 == 0){
        printf("É um número par\n");
    } else{
        printf("É um número impar\n");
    }
}