
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[201];
    int gols_marcados;
    int gols_sofridos;
} Time;

void ordenarTimes(Time times[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (times[j].gols_marcados < times[j + 1].gols_marcados) {
                Time temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int n;

    scanf("%d", &n);
    getchar();

    Time times[n];

    for (int i = 0; i < n; i++) {
        fgets(times[i].nome, sizeof(times[i].nome), stdin);
        times[i].nome[strcspn(times[i].nome, "\n")] = '\0';

        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
        getchar();
    }

    ordenarTimes(times, n);

    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", i + 1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
    }

    return 0;
}
