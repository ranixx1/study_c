
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 51

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char nome[], int idade, char sexo) {
    Pessoa p;

    strcpy(p.nome, nome);
    p.idade = idade;
    p.sexo = sexo;

    return p;
}

Pessoa *inserir(Pessoa *pessoas, int *quantidade, Pessoa nova) {
    Pessoa *temp = realloc(pessoas, (*quantidade + 1) * sizeof(Pessoa));

    if (temp == NULL) {
        free(pessoas);
        exit(1);
    }

    pessoas = temp;
    pessoas[*quantidade] = nova;
    (*quantidade)++;

    return pessoas;
}

int iguais(Pessoa a, Pessoa b) {
    return strcmp(a.nome, b.nome) == 0 &&
           a.idade == b.idade &&
           a.sexo == b.sexo;
}

Pessoa *deletar(Pessoa *pessoas, int *quantidade, Pessoa alvo) {
    for (int i = 0; i < *quantidade; i++) {
        if (iguais(pessoas[i], alvo)) {
            for (int j = i; j < *quantidade - 1; j++) {
                pessoas[j] = pessoas[j + 1];
            }

            (*quantidade)--;

            if (*quantidade == 0) {
                free(pessoas);
                return NULL;
            }

            Pessoa *temp = realloc(pessoas, *quantidade * sizeof(Pessoa));

            if (temp != NULL) {
                pessoas = temp;
            }

            break;
        }
    }

    return pessoas;
}

void imprimir(Pessoa pessoas[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("%s,%d,%c\n",
               pessoas[i].nome,
               pessoas[i].idade,
               pessoas[i].sexo);
    }
}

int main(void) {
    Pessoa *pessoas = NULL;
    int quantidade = 0;
    char operacao;

    while (scanf(" %c", &operacao) == 1) {
        if (operacao == 'i') {
            char nome[MAX_NOME];
            int idade;
            char sexo;

            getchar();
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            scanf("%d", &idade);
            scanf(" %c", &sexo);

            Pessoa nova = criar(nome, idade, sexo);
            pessoas = inserir(pessoas, &quantidade, nova);

        } else if (operacao == 'd') {
            char nome[MAX_NOME];
            int idade;
            char sexo;

            getchar();
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            scanf("%d", &idade);
            scanf(" %c", &sexo);

            Pessoa alvo = criar(nome, idade, sexo);
            pessoas = deletar(pessoas, &quantidade, alvo);

        } else if (operacao == 'p') {
            imprimir(pessoas, quantidade);
            break;
        }
    }

    free(pessoas);
    return 0;
}
