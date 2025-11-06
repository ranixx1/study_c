#include <stdio.h>
 
int main() {
 
    int inicio;
    scanf("%d", &inicio);
    int fim;
    scanf("%d",&fim);
    int soma = 0;
 
    if (inicio > fim) {
        int temp = inicio; 
        inicio = fim;
        fim = temp;
    }
 
    for(int i = inicio; i <= fim; i++){
        if(i % 13 != 0){
            soma += i;
        }
    }
 
    printf("%d\n", soma);
    
    return 0;
}