#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int num1 = get_int("Digite o primeiro numero (valor inicial): ");
    int num2 = get_int("Digite o segundo numero (valor final): ");
    int incremento = get_int("Digite o valor para ser somado a cada vez: ");

    int contador_somas = 0;

    if (incremento == 0)
    {
        printf("\nO valor de incremento nao pode ser zero. Por favor, digite um numero diferente de zero.\n");
        return 1;
    }

    if (num1 == num2)
    {
        contador_somas = 0;
    }
    else if (num1 > num2 && incremento > 0)
    {
        printf("\nO primeiro numero (%d) ja e maior que o segundo (%d), e o incremento e positivo (%d).\n", num1, num2, incremento);
        printf("Nao e possivel alcancar o segundo numero somando um valor positivo.\n");
        return 0;
    }
    else if (num1 < num2 && incremento < 0)
    {
        printf("\nO primeiro numero (%d) e menor que o segundo (%d), mas o incremento e negativo (%d).\n", num1, num2, incremento);
        printf("Nao e possivel alcancar o segundo numero subtraindo um valor negativo.\n");
        return 0;
    }
    else
    {
        float diferenca = (float)num2 - num1;
        int somas_necessarias = (int)ceil(diferenca / incremento);

        if (somas_necessarias < 0) {
            somas_necessarias = -somas_necessarias;
        }

        for (int i = 0; i < somas_necessarias; i++)
        {
            contador_somas++;
        }
    }

    printf("\nO primeiro numero se tornaria igual ou ultrapassaria o segundo apos %d soma(s) do valor %d.\n", contador_somas, incremento);

    return 0;
}