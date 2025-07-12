#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <cs50.h>
#include <stdbool.h>

typedef enum
{
    STATUS_OK,
    STATUS_ERRO_DUPLICADO,
    STATUS_ERRO_NAO_ENCONTRADO,
    STATUS_ERRO_MEMORIA
} StatusInventario;

typedef struct inventario_t Inventario;

Inventario* inventario_criar(void);
void inventario_liberar(Inventario* inv);

StatusInventario inventario_criar_item(Inventario* inv, string chamado, string descricao);
StatusInventario inventario_remover_item(Inventario* inv, string chamado);
StatusInventario inventario_editar_item(Inventario* inv, string chamado, string nova_descricao);


bool inventario_ver_item(const Inventario* inv, string chamado);
void inventario_ver_todos_os_itens(const Inventario* inv);

int inventario_obter_contagem(const Inventario* inv);

#endif 