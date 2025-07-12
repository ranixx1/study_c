#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

#define CAPACIDADE_INICIAL 8

typedef struct
{
    string chamado;
    string descricao;
} Item;

struct inventario_t
{
    Item* itens;
    int contador_atual;
    int capacidade;
};

static int encontrar_item_por_chamado(const Inventario* inv, string chamado)
{
    for (int i = 0; i < inv->contador_atual; i++)
    {
        if (strcmp(inv->itens[i].chamado, chamado) == 0)
        {
            return i;
        }
    }
    return -1;
}

static bool inventario_expandir(Inventario* inv)
{
    int nova_capacidade = inv->capacidade * 2;
    Item* novos_itens = realloc(inv->itens, nova_capacidade * sizeof(Item));

    if (novos_itens == NULL)
    {
        fprintf(stderr, "Erro fatal: Falha ao alocar memória para expandir o inventário.\n");
        return false;
    }

    inv->itens = novos_itens;
    inv->capacidade = nova_capacidade;
    return true;
}

Inventario* inventario_criar(void)
{
    Inventario* inv = malloc(sizeof(Inventario));
    if (inv == NULL)
    {
        return NULL;
    }

    inv->contador_atual = 0;
    inv->capacidade = CAPACIDADE_INICIAL;
    inv->itens = malloc(inv->capacidade * sizeof(Item));
    if (inv->itens == NULL)
    {
        free(inv);
        return NULL;
    }

    return inv;
}

void inventario_liberar(Inventario* inv)
{
    if (inv == NULL) return;

    for (int i = 0; i < inv->contador_atual; i++)
    {
        free(inv->itens[i].chamado);
        free(inv->itens[i].descricao);
    }
    free(inv->itens);
    free(inv);
}

StatusInventario inventario_criar_item(Inventario* inv, string chamado, string descricao)
{
    if (encontrar_item_por_chamado(inv, chamado) != -1)
    {
        return STATUS_ERRO_DUPLICADO;
    }

    if (inv->contador_atual >= inv->capacidade)
    {
        if (!inventario_expandir(inv))
        {
            return STATUS_ERRO_MEMORIA;
        }
    }

    int i = inv->contador_atual;

    inv->itens[i].chamado = malloc(strlen(chamado) + 1);
    inv->itens[i].descricao = malloc(strlen(descricao) + 1);

    if (inv->itens[i].chamado == NULL || inv->itens[i].descricao == NULL)
    {
        free(inv->itens[i].chamado);
        free(inv->itens[i].descricao);
        return STATUS_ERRO_MEMORIA;
    }

    strcpy(inv->itens[i].chamado, chamado);
    strcpy(inv->itens[i].descricao, descricao);

    inv->contador_atual++;
    return STATUS_OK;
}

StatusInventario inventario_remover_item(Inventario* inv, string chamado)
{
    int index = encontrar_item_por_chamado(inv, chamado);
    if (index == -1)
    {
        return STATUS_ERRO_NAO_ENCONTRADO;
    }

    free(inv->itens[index].chamado);
    free(inv->itens[index].descricao);

    int ultimo_index = inv->contador_atual - 1;
    if (index != ultimo_index)
    {
        inv->itens[index] = inv->itens[ultimo_index];
    }

    inv->contador_atual--;
    return STATUS_OK;
}

StatusInventario inventario_editar_item(Inventario* inv, string chamado, string nova_descricao)
{
    int index = encontrar_item_por_chamado(inv, chamado);
    if (index == -1)
    {
        return STATUS_ERRO_NAO_ENCONTRADO;
    }

    char* nova_memoria = realloc(inv->itens[index].descricao, strlen(nova_descricao) + 1);
    if (nova_memoria == NULL)
    {
        return STATUS_ERRO_MEMORIA;
    }
    
    inv->itens[index].descricao = nova_memoria;
    strcpy(inv->itens[index].descricao, nova_descricao);

    return STATUS_OK;
}

bool inventario_ver_item(const Inventario* inv, string chamado)
{
    int index = encontrar_item_por_chamado(inv, chamado);
    if (index != -1)
    {
        printf("Detalhes do item '%s':\n", chamado);
        printf("  Descrição: %s\n", inv->itens[index].descricao);
        return true;
    }
    else
    {
        printf("Erro: O item '%s' não foi encontrado no inventário.\n", chamado);
        return false;
    }
}

void inventario_ver_todos_os_itens(const Inventario* inv)
{
    if (inv->contador_atual == 0)
    {
        printf("O inventário está vazio.\n");
        return;
    }

    printf("Itens no inventário (%d/%d):\n", inv->contador_atual, inv->capacidade);
    for (int i = 0; i < inv->contador_atual; i++)
    {
        printf("- %s: %s\n", inv->itens[i].chamado, inv->itens[i].descricao);
    }
}
int inventario_obter_contagem(const Inventario* inv)
{
    if (inv == NULL)
    {
        return 0;
    }
    return inv->contador_atual;
}
