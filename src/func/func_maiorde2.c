#include <cs50.h>
#include <stdio.h>

int maior_de_2(int n1, int n2);


int main(void)
{
    int n1 = get_int("Digite um numero: \n");
    int n2 = get_int("Digite um numero: \n");
    printf("o maior entre os números é: %i\n", maior_de_2(n1, n2));
}

int maior_de_2(int n1, int n2)
{
    if (n1>n2){
        return n1;
    } else {
        return n2;
    }
}