#include <stdio.h>
#include <stdlib.h>
#include "lista_contatos.h"

int main()
{
    int option; //Para as opções do menu
    int codigo; // Para pesquisa de contato por codigo
    int x; //Para código de erro
    Lista *li; //Ponteiro para a lista
    CLIENTE novo_contato; //Para inserção de dados do novo contato
    CLIENTE consulta_contato; //Para Consulta de dados de contatos da lista

    li = criaLista();
    if(li == NULL){ //Se lista não criada, aborta o programa.
        abortaPrograma();
    }

    do{
        system("cls"); // Limpa a tela no Windows

        printf(  "                            MENU"); // Inserir espaços ante das aspas para o texto do código ficar semelhante ao da saída
        printf("\n[1] - Adicionar novo contato  | [2] - Exibir todos os contatos");
        printf("\n[3] - Buscar contato [Codigo] | [4] - Buscar contato [Nome]");
        printf("\n[5] - Editar contato          | [6] - Remover contato");
        printf("\n[0] - Sair\n");

        printf("\nEntrada: ");
        scanf(" %d", &option); // Ler a entrada do usuário para escolha de opções

        switch(option){
            case 1: // Adicionar novo contato
                printf("\nOpcao 1 selecionada.\n"); // Para debugg

                printf("\nNOVO CONTATO");

                printf("\nCodigo: ");
                scanf("%d", &novo_contato.codigo);
                printf("Nome: ");
                getchar();
                fgets(novo_contato.nome, sizeof(novo_contato.nome) - 1, stdin);
                printf("Empresa: ");
                fgets(novo_contato.empresa, sizeof(novo_contato.empresa) - 1, stdin);
                printf("Departamento: ");
                fgets(novo_contato.departamento, sizeof(novo_contato.departamento) - 1, stdin);
                printf("Telefone:");
                fgets(novo_contato.telefone, sizeof(novo_contato.telefone) - 1, stdin);
                printf("Celular: ");
                fgets(novo_contato.celular, sizeof(novo_contato.celular) - 1, stdin);
                printf("Email: ");
                fgets(novo_contato.email, sizeof(novo_contato.email) - 1, stdin);

                /* // Para debug
                printf("\n\nNOVO CONTATO:");
                printf("\nCodigo: %d", novo_contato.codigo);
                printf("\nNome: %s", novo_contato.nome);
                printf("Empresa: %s", novo_contato.empresa);
                printf("Departamento: %s", novo_contato.departamento);
                printf("Telefone: %s", novo_contato.telefone);
                printf("Celular: %s", novo_contato.celular);
                printf("Email: %s", novo_contato.email);
                */

                x = insereOrdenado(li, novo_contato);
                if(x){
                    printf("\nInserido contato do cliente de codigo %d\n", novo_contato.codigo);
                }else{
                    printf("\nErro. Não foi possivel adicionar novo contato.\n");
                }

                break;

            case 2: // Exibir todos os contatos
                printf("\nOpcao 2 selecionada.\n"); // Para debugg

                apresentaClientes(*li);

                break;

            case 3: // Buscar contato [Codigo]
                do{
                    printf("Buscar contato de codigo: ");
                    scanf("%d", &codigo);
                    x = consultaCodigo(li, codigo, &consulta_contato);
                    if(x){
                        imprimirContato(consulta_contato);
                        option = -3;
                    }else{
                        printf("\nCodigo nao encontrado.");
                        printf("\nRealizar uma nova busca? [1] SIM | [0] NAO: ");
                        scanf("%d", &option);
                        if(option == 0){
                            option = -3;
                        }
                    }
                }while(option != -3); // Código para sair do loop da opção 3
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

            default: // Entradas inválidas
                printf("\nEntrada invalida! Insira novamente...\n");
                printf("\nEntrada inserida: %d", option); // Para debug
                break;
        }
        system("PAUSE");
    }while(option != 0); // Encerra o loop ao inserir a opção "Sair"

    apagaLista(li);
    printf("\nPrograma encerrado!\n");
    return 0;
}
