
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char **PARTICIPANTES = NULL;
    int N = 0;

    char nome[200];

    while (1) {

        scanf(" %199[^\n]", nome);

        if (strcmp(nome, "acabou") == 0) {
            break;
        }

        PARTICIPANTES = realloc(PARTICIPANTES, (N + 1) * sizeof(char *));

        PARTICIPANTES[N] = malloc(strlen(nome) + 1);
        strcpy(PARTICIPANTES[N], nome);

        N++;
    }

    int S;
    scanf("%d", &S);

    srand(S);

    int *sorteados = calloc(N, sizeof(int));

    int quantidade = 0;

    while (quantidade < N) {

        int indice_participante = rand() % N;

        if (sorteados[indice_participante] == 0) {

            printf("%s\n", PARTICIPANTES[indice_participante]);

            sorteados[indice_participante] = 1;
            quantidade++;
        }
    }

    for (int i = 0; i < N; i++) {
        free(PARTICIPANTES[i]);
    }

    free(PARTICIPANTES);
    free(sorteados);

    return 0;
}
