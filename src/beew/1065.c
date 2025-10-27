#include <stdio.h>
 
int main() {
    int soma = 0;
    int n;
 
    for(int i = 0; i < 5; i++) {
        scanf("%d", &n); 
        
        if(n % 2 == 0) {
            soma += 1;
        }
    }
 
    printf("%d valores pares\n", soma); 
 
    return 0;
}