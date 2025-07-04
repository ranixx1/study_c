#include <cs50.h>
#include <stdio.h>

void verificar_senha(int senha_correta, int senha_solicitada_inicial);


int main(void)
{
    int senha_definida = 13452;
    int senha_inicial_usuario = 0;

    printf("Digite uma senha:\n");

    verificar_senha(senha_definida, senha_inicial_usuario);

    return 0;
}

void verificar_senha(int senha_correta, int senha_solicitada)
{
    senha_solicitada = get_int(">"); 

    while (senha_solicitada != senha_correta)
    {
        printf("Acesso negado\n");
        senha_solicitada = get_int("Digite novamente sua senha:\n>");
    }

    printf("Acesso permitido\n");
}