#include <stdio.h>

int main() {
    char numero[8];
    
    scanf("%7s", numero);
    
    for (int i = 0; numero[i] != '\0'; i++) {
        printf("%c\n", numero[i]);
    }
    
    return 0;
}