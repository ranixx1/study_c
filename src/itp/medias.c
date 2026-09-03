#include <stdio.h>
#include <math.h>

int main()
{
    double soma = 0.0;
    double soma_inversos = 0.0;
    double produto = 1.0;
    
    for (int i = 0; i <= 9; i++)
    {
        double n;
        scanf("%lf", &n);
        soma += n;
        soma_inversos += (1.0 / n);
        produto *= n;
    }

    double media_aritmetica = soma / 10;
    double media_harmonica = 10 / soma_inversos;
    double media_geometrica = pow(produto, 1.0 / 10);

    printf("Média aritmética é %.2f\n", media_aritmetica);
    printf("Média harmônica é %.2f\n", media_harmonica);
    printf("Média geométrica é %.2f\n", media_geometrica);

    double erro_harmonica = (media_harmonica - media_aritmetica) / media_aritmetica;
    double erro_geometrica = (media_geometrica - media_aritmetica) / media_aritmetica;
    double erro_medio = ((erro_harmonica + erro_geometrica) / 2) * 100;

    printf("Erro médio é %.2f %%\n", erro_medio);

    return 0;
}