#include <cs50.h>
#include <stdio.h>

int busca_menor(int arr[], int tamanho)
{
    int menor = arr[0];
    int menor_indice = 0;
    for (int i =1; i<tamanho; i++)
    {
        if(arr[i]<menor){
            menor = arr[i];
            menor_indice= i;
        }
    }
    return menor_indice;
}
int main(void)
{
    int arr[] = {5,3,6,2,10};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    int indice_menor = busca_menor(arr,tamanho);
    printf("O menor elemento está no indice: %i\n", indice_menor);
    printf("Valor do menor elemento: %i\n", arr[indice_menor]);
}