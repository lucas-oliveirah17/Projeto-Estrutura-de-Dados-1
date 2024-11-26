#include <stdio.h>
#include <stdlib.h>
#include "lista_contatos.h"

int main()
{
    int option; // Vari�vel para as op��es do menu
    int x; // Vari�vel para c�digo de erro

    do{
        system("cls"); // Limpa a tela no Windows

        printf(  "                            MENU"); // Inserir espa�os ante das aspas para o texto do c�digo ficar semelhante ao da sa�da
        printf("\n[1] - Adicionar novo contato  | [2] - Exibir todos os contatos");
        printf("\n[3] - Buscar contato [Codigo] | [4] - Buscar contato [Nome]");
        printf("\n[5] - Editar contato          | [6] - Remover contato");
        printf("\n[0] - Sair\n");

        printf("\nEntrada: ");
        scanf(" %d", &option); // Ler a entrada do usu�rio para escolha de op��es

        switch(option){
            case 1: // Adicionar novo contato
                printf("\nOpcao 1 selecionada.\n"); // Para debugg
                break;
            case 2: // Exibir todos os contatos
                printf("\nOpcao 2 selecionada.\n"); // Para debugg
                break;
            case 3: // Buscar contato [Codigo]
                printf("\nOpcao 3 selecionada.\n"); // Para debugg
                break;
            case 4: // Buscar contato [Nome]
                printf("\nOpcao 4 selecionada.\n"); // Para debugg
                break;
            case 5: // Editar contato
                printf("\nOpcao 5 selecionada.\n"); // Para debugg
                break;
            case 6: // Remover contato
                printf("\nOpcao 6 selecionada.\n"); // Para debugg
                break;
            case 0: // Remover contato
                printf("\nOpcao 0 selecionada.\n"); // Para debugg
                break;
            default: // Entradas inv�lidas
                printf("\nEntrada invalida! Insira novamente...\n");
                printf("\n%d", option);
                break;
        }
        system("PAUSE");
    }while(option != 0); // Encerra o loop ao inserir a op��o "Sair"

    printf("\nPrograma encerrado\n\n");
    system("PAUSE");
    return 0;
}
