#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Item;

int main() {
    Item itens[100];
    int total = 0;
    int opcao;

    do {
        scanf(" %[^\n]", itens[total].nome);
        scanf("%f", &itens[total].preco);
        scanf("%d", &itens[total].quantidade);
        scanf("%d", &opcao);
        total++;
    } while (opcao == 1);

    int pessoas;
    scanf("%d", &pessoas);

    float valor_total = 0;
    for (int i = 0; i < total; i++) {
        valor_total += itens[i].preco * itens[i].quantidade;
    }

    float por_pessoa = 0;
    if (pessoas > 0) {
        por_pessoa = valor_total / pessoas;
    }

    printf("Valor: R$ %.2f\n", valor_total);
    printf("Divisão R$ %.2f para cada participante.\n", por_pessoa);

    return 0;
}