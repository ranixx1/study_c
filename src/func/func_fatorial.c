#include <cs50.h>
#include <stdio.h>

int calcular_fatorial(long long n);

int main(void)
{
    long long n;
    do
    {
        n = get_long_long("Digite um numero nao-negativo (max 20 para evitar overflow): ");
    }
    while (n < 0 || n > 20);

    long long resultado_fatorial = calcular_fatorial(n);
    printf("O fatorial de %lld e: %lld\n", n, resultado_fatorial);
    return 0;
}


int calcular_fatorial(long long n)
{
    if (n <=1)
    {
        return 1;
    } else {
        return n*calcular_fatorial(n-1);
    }
    
}