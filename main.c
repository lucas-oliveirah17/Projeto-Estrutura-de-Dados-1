#include <stdio.h>
#include <stdlib.h>
#include "lista_contatos.h"

int main()
{
    int option; //Para as opções do menu
    int codigo; // Para pesquisa de contato por codigo
    int x; //Para código de erro
    Lista *li; //Ponteiro para a lista
    CLIENTE novo_contato; //Para inserção de dados na lista de contato
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
                if(consultaCodigo(li, novo_contato.codigo, &consulta_contato)){ // Verifica se há um cliente cadastro com o código
                    printf("\nJa exite um cliente com esse codigo na lista.\n");
                    break;
                }

                novo_contato = coletaDados(novo_contato.codigo); // Coleta dados para o novo contato

                x = insereOrdenado(li, novo_contato);
                if(x){
                    printf("\nInserido contato do cliente de codigo %d\n", novo_contato.codigo);
                }else{
                    printf("\nErro. Não foi possivel adicionar novo contato.\n");
                }
                break;

            case 2: // Exibir todos os contatos
                apresentaClientes(*li);
                break;

            case 3: // Buscar contato [Codigo]
                do{
                    printf("Buscar contato de codigo: ");
                    scanf("%d", &codigo);
                    x = consultaCodigo(li, codigo, &consulta_contato);
                    if(x){
                        imprimirContato(consulta_contato);
                        break;
                    }else{
                        printf("\nCodigo nao encontrado.");
                        while(1){
                            printf("\nRealizar uma nova busca? [1] SIM | [0] NAO: ");
                            scanf("%d", &option);
                            if(option == 1 || option == 0){
                                break;
                            }
                            printf("\nEntrada invalida!\n");
                        }

                        if(option == 0){
                            option = -1;
                            break;
                        }
                    }
                }while(option != -3); // Código para sair do loop da opção 3
                break;

            case 4: // Buscar contato [Nome]
                printf("\nOpcao 4 selecionada.\n"); // Para debugg
                break;

            case 5: // Editar contato
                printf("\nOpcao 5 selecionada.\n"); // Para debugg
                printf("\nEditar contato de codigo: ");
                scanf("%d", &codigo);
                x = consultaCodigo(li, codigo, &consulta_contato);
                if(x){
                        imprimirContato(consulta_contato);

                        while(1){
                            printf("\nEditar contato? [1] SIM | [0] NAO: ");
                            scanf("%d", &option);
                            if(option == 1){
                                x = editaContato(li, codigo);
                                if(x){
                                    printf("\nDados editado.\n");
                                }
                                else{
                                    printf("\nErro. Falha na edicao.\n");
                                }
                                break; // Para sair do loop
                            }else if(option == 0){
                                printf("\nOperacao cancelada.\n");
                                option = -1;
                                break; // Para sair do loop
                            }else{
                                printf("\nEntrada invalida!\n");
                            }
                        }
                }

                break;

            case 6: // Remover contato
                do{
                    printf("Remover contato de codigo: ");
                    scanf("%d", &codigo);
                    x = consultaCodigo(li, codigo, &consulta_contato);
                    if(x){
                        imprimirContato(consulta_contato);
                        printf("\nExcluir contato? [1] SIM | [0] NAO: ");
                        scanf("%d", &option);
                        if(option == 1) {
                            x = removeOrdenado(li, codigo);
                            if(x){
                                printf("\nContato de codigo %d removido!\n", x);
                                //option = -3;
                                break;
                            }else{
                                printf("\nErro! Contato nao removido.\n");
                            }
                        }else if(option == 0){
                            printf("\nOperacao cancelada.\n");
                            option = -1;
                            //option = -3;
                            break;
                        }else{
                            printf("\nEntrada invalida!\n");
                        }
                    }else{
                        printf("\nCodigo nao encontrado.\n");
                        break;
                    }
                }while(option != -3); // Código para sair do loop da opção 3
                break;

            case 0: // REncerrar programa
                break;

            default: // Entradas inválidas
                printf("\nEntrada invalida! Insira novamente...\n");
                printf("\nEntrada inserida: %d (DEBUG)\n", option); // Para debug
                break;
        }
        system("PAUSE");
    }while(option != 0); // Encerra o loop ao inserir a opção "Sair"

    apagaLista(li);
    printf("\nPrograma encerrado\n\n");
    system("PAUSE");
    return 0;
}
