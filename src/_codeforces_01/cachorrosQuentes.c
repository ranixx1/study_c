#include <stdio.h>

int main(void)
{
    int participantes, numero_total;
    scanf("%d %d", &participantes, &numero_total);
    double participante_por_comida = (double)participantes/numero_total;
    printf("%.2f\n", participante_por_comida);
    return 0;
}