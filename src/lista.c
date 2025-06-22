#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int minha_lista[5]; 

    minha_lista[0] = 10;
    minha_lista[1] = 20;
    minha_lista[2] = 30;
    minha_lista[3] = 40;
    minha_lista[4] = 50;

    printf("Elemento º%d: %d\n ",3, minha_lista[2]); // or printf("Elemento º3: %d\n ", minha_lista[2]);
    printf("--- Lista preenchida manualmente ---\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Elemento na posicao %d: %d\n", i, minha_lista[i]);
    }
}