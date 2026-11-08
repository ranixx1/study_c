
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char *nome, int idade, char sexo) {
    Pessoa p;

    p.nome = malloc(strlen(nome) + 1);
    strcpy(p.nome, nome);

    p.idade = idade;
    p.sexo = sexo;

    return p;
}

void inserir(Pessoa **vetor, int *quantidade, int *capacidade, Pessoa p) {

    if (*quantidade == *capacidade) {
        *capacidade = (*capacidade == 0) ? 1 : *capacidade * 2;

        *vetor = realloc(*vetor, *capacidade * sizeof(Pessoa));
    }

    (*vetor)[*quantidade] = p;
    (*quantidade)++;
}

void deletar(Pessoa *alvo, Pessoa *vetor, int *quantidade) {

    for (int i = 0; i < *quantidade; i++) {

        if (strcmp(vetor[i].nome, alvo->nome) == 0 &&
            vetor[i].idade == alvo->idade &&
            vetor[i].sexo == alvo->sexo) {

            free(vetor[i].nome);

            for (int j = i; j < *quantidade - 1; j++) {
                vetor[j] = vetor[j + 1];
            }

            (*quantidade)--;

            return;
        }
    }
}

void imprimir(Pessoa *vetor, int quantidade) {

    for (int i = 0; i < quantidade; i++) {

        printf("%s,%d,%c", vetor[i].nome,
               vetor[i].idade,
               vetor[i].sexo);

        if (i < quantidade - 1) {
            printf("\n");
        }
    }

    printf("\n");
}

int main() {

    Pessoa *vetor = NULL;

    int quantidade = 0;
    int capacidade = 0;

    char operacao;

    while (scanf(" %c", &operacao) == 1) {

        if (operacao == 'p') {
            imprimir(vetor, quantidade);
            break;
        }

        if (operacao == 'i' || operacao == 'd') {

            char *nome = NULL;
            size_t tamanho = 0;

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            getline(&nome, &tamanho, stdin);

            nome[strcspn(nome, "\n")] = '\0';

            int idade;
            char sexo;

            scanf("%d %c", &idade, &sexo);

            Pessoa p = criar(nome, idade, sexo);

            if (operacao == 'i') {
                inserir(&vetor, &quantidade, &capacidade, p);
            } else {
                deletar(&p, vetor, &quantidade);
                free(p.nome);
            }

            free(nome);
        }
    }

    for (int i = 0; i < quantidade; i++) {
        free(vetor[i].nome);
    }

    free(vetor);

    return 0;
}
