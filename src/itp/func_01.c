#include <stdio.h>
#include <stdbool.h>

bool ehPar(int x) {
    if (x % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    bool resultado = ehPar(n);
    
    if (resultado) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}