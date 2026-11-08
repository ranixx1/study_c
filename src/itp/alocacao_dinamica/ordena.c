
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *vetor = NULL;
    int N = 0;
    int numero;

    while (scanf("%d", &numero) == 1) {

        vetor = realloc(vetor, (N + 1) * sizeof(int));

        vetor[N] = numero;
        N++;

        if (getchar() == '\n') {
            break;
        }
    }

    for (int i = 0; i < N - 1; i++) {

        for (int j = 0; j < N - 1 - i; j++) {

            if (vetor[j] > vetor[j + 1]) {

                int temp = vetor[j];

                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {

        printf("%d", vetor[i]);

        if (i < N - 1) {
            printf(" ");
        }
    }

    printf("\n");

    free(vetor);

    return 0;
}
