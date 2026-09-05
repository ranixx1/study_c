#include <stdio.h>

int main() {
    double tempo_maximo;
    if (scanf("%lf", &tempo_maximo) != 1) return 0;

    int atletas_aptos = 0;
    double tempo_atleta;

    while (1) {
        scanf("%lf", &tempo_atleta);

        if (tempo_atleta < 0) {
            break;
        }

        if (tempo_atleta <= tempo_maximo) {
            atletas_aptos++;
        }
    }

    int series = atletas_aptos / 8;
    if (atletas_aptos % 8 != 0) {
        series++; 
    }

    printf("%d %d\n", atletas_aptos, series);


    return 0;
}
