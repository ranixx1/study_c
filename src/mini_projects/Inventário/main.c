#include <stdio.h>
#include <cs50.h>
#include "inventario.h"

void exibir_menu(void);
void tratar_criar_item(Inventario* inv);
void tratar_remover_item(Inventario* inv);
void tratar_editar_item(Inventario* inv);
void tratar_detalhar_item(Inventario* inv);

int main(void)
{
    Inventario* meu_inventario = inventario_criar();
    if (meu_inventario == NULL)
    {
        fprintf(stderr, "Erro crítico: Não foi possível alocar memória para o inventário.\n");
        return 1;
    }

    while (true)
    {
        exibir_menu();
        int escolha = get_int("Escolha uma opção: ");

        switch (escolha)
        {
            case 1:
                tratar_criar_item(meu_inventario);
                break;
            case 2:
                inventario_ver_todos_os_itens(meu_inventario);
                break;
            case 3:
                tratar_detalhar_item(meu_inventario);
                break;
            case 4:
                tratar_editar_item(meu_inventario);
                break;
            case 5:
                tratar_remover_item(meu_inventario);
                break;
            case 0:
                inventario_liberar(meu_inventario);
                printf("Sistema finalizado. Memória liberada.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        printf("\nPressione Enter para continuar...");
        getchar();
    }
}

void exibir_menu(void)
{
    printf("\n--- SISTEMA DE INVENTÁRIO ---\n");
    printf("1. Criar novo item\n");
    printf("2. Listar todos os itens\n");
    printf("3. Detalhar um item\n");
    printf("4. Editar um item\n");
    printf("5. Apagar um item\n");
    printf("0. Sair\n");
    printf("-----------------------------\n");
}

void tratar_criar_item(Inventario* inv)
{
    string chamado = get_string("Digite o nome do novo item: ");
    string descricao = get_string("Digite a descrição do novo item: ");

    StatusInventario status = inventario_criar_item(inv, chamado, descricao);

    if (status == STATUS_OK)
    {
        printf("Item '%s' criado com sucesso!\n", chamado);
    }
    else if (status == STATUS_ERRO_DUPLICADO)
    {
        printf("Erro: O item com chamado '%s' já existe.\n", chamado);
    }
    else if (status == STATUS_ERRO_MEMORIA)
    {
        printf("Erro: Falha ao alocar memória para o novo item.\n");
    }
}

void tratar_remover_item(Inventario* inv)
{
    printf("\n--- Apagar Item ---\n");
    inventario_ver_todos_os_itens(inv);

    if (inventario_obter_contagem(inv) > 0)
    {
        string chamado = get_string("Digite o chamado do item a ser REMOVIDO: ");
        StatusInventario status = inventario_remover_item(inv, chamado);

        if (status == STATUS_OK)
        {
            printf("Item '%s' removido com sucesso!\n", chamado);
        }
        else
        {
            printf("Erro: Item '%s' não encontrado no inventário.\n", chamado);
        }
    }
}

void tratar_editar_item(Inventario* inv)
{
    printf("\n--- Editar Item ---\n");
    inventario_ver_todos_os_itens(inv);

    if (inventario_obter_contagem(inv) > 0)
    {
        string chamado = get_string("Digite o chamado do item a ser EDITADO: ");
        string nova_descricao = get_string("Digite a NOVA descrição: ");

        StatusInventario status = inventario_editar_item(inv, chamado, nova_descricao);

        if (status == STATUS_OK)
        {
            printf("Item '%s' atualizado com sucesso!\n", chamado);
        }
        else
        {
            printf("Erro: Item '%s' não encontrado no inventário.\n", chamado);
        }
    }
}

void tratar_detalhar_item(Inventario* inv)
{
    printf("\n--- Detalhar Item ---\n");
    inventario_ver_todos_os_itens(inv);

    // Só pede para digitar se o inventário não estiver vazio
    if (inventario_obter_contagem(inv) > 0)
    {
        string chamado = get_string("Digite o chamado do item que deseja ver: ");
        inventario_ver_item(inv, chamado);
    }
}