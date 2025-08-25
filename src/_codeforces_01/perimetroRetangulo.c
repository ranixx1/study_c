#include <stdio.h>

int main(void)
{
    int l1, l2;
    printf("Digite os lados do retângulo:\n");
    scanf("%d %d", &l1,&l2);

    int perimetro = l1*2 + l2*2;
    printf("O perimetro do retângulo é: %i\n",perimetro);
    return 0;
}