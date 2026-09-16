#include <stdio.h>

void numeroPerfeito(int x) {
    int soma = 0;
    
    for(int i = 1; i < x; i++) {
        if(x % i == 0) {
            soma += i;
        }
    }
    
    if(soma == x) {
        printf("%d eh perfeito\n", x);
    } else {
        printf("%d nao eh perfeito\n", x);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        numeroPerfeito(x);
    }

    return 0;
}