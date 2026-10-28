
#include <stdio.h>
#include <string.h>

#define MAX_TIMES 1000
#define MAX_NOME 201

typedef struct {
    char nome[MAX_NOME];
    int vitorias;
    int empates;
    int derrotas;
    int gols_feitos;
    int gols_sofridos;
    int pontos;
    int partidas;
    int saldo_gols;
} Time;

void lerTimes(Time times[], int T) {
    char linha[300];

    for (int i = 0; i < T; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';

        char *separador = strchr(linha, ';');

        *separador = '\0';

        strcpy(times[i].nome, linha);

        sscanf(separador + 1, "%d %d %d %d %d",
               &times[i].vitorias,
               &times[i].empates,
               &times[i].derrotas,
               &times[i].gols_feitos,
               &times[i].gols_sofridos);

        times[i].pontos = times[i].vitorias * 3 + times[i].empates;

        times[i].partidas = times[i].vitorias
                          + times[i].empates
                          + times[i].derrotas;

        times[i].saldo_gols = times[i].gols_feitos
                            - times[i].gols_sofridos;
    }
}

int vemAntes(Time a, Time b) {
    if (a.pontos != b.pontos)
        return a.pontos > b.pontos;

    if (a.vitorias != b.vitorias)
        return a.vitorias > b.vitorias;

    if (a.saldo_gols != b.saldo_gols)
        return a.saldo_gols > b.saldo_gols;

    return 1;
}

void ordenarTimes(Time times[], int T) {
    for (int i = 0; i < T - 1; i++) {
        for (int j = 0; j < T - 1 - i; j++) {
            if (!vemAntes(times[j], times[j + 1])) {
                Time temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }
}

void imprimirTabela(Time times[], int T) {
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");

    for (int i = 0; i < T; i++) {
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n",
               times[i].nome,
               times[i].pontos,
               times[i].partidas,
               times[i].vitorias,
               times[i].empates,
               times[i].derrotas,
               times[i].gols_feitos,
               times[i].gols_sofridos,
               times[i].saldo_gols);
    }

    printf("\nTimes na zona da libertadores: \n");

    int limite = T < 6 ? T : 6;

    for (int i = 0; i < limite; i++) {
        printf("%s\n", times[i].nome);
    }

    printf("\nTimes rebaixados: \n");

    int limite_rebaixamento = T < 4 ? T : 4;

    for (int i = T - 1; i >= T - limite_rebaixamento; i--) {
        printf("%s\n", times[i].nome);
    }
}

int main(void) {
    int T;

    scanf("%d", &T);
    getchar();

    if (T < 0 || T > MAX_TIMES)
        return 1;

    Time times[MAX_TIMES];

    lerTimes(times, T);
    ordenarTimes(times, T);
    imprimirTabela(times, T);

    return 0;
}
