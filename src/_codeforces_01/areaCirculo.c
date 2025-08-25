#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    double raio = get_double("Digite o valor do raio: ");
    int expoente = 2;
    double circ = 3.14159;
    double raio_resul = pow(raio,expoente);
    printf("%f\n" ,raio_resul * circ);
    return 0;
}

