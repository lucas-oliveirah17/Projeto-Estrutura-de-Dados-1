// Arquivo main.c
/*
    Projeto - Lista de Contatos - IFSP GUARULHOS - ADS
    NOME: Daniel Navarro Porto      Prontuário: GU3052958
    NOME: Lucas Silva de Oliveira   Prontuário: GU3054314
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_contatos.h"

int main()
{
    int option; // Opções do menu
    int codigo; // Para consuulta de contato por codigo
    int x; // Código de erro
    char name[50]; // Para consulta de nome
    Lista *li; // Ponteiro para a lista
    CLIENTE novo_contato; // Para inserção de dados na lista de contato
    CLIENTE consulta_contato; // Para Consulta de dados de contatos da lista

    li  = criaLista(); // Criação da lista
    // Carregar contatos a partir de um arquivo
    carregaContatos(li, "contatos.txt");

    do{
        system("cls"); // Limpa a tela no Windows
        // Inserido espaços ante das aspas no primeiro printf para o texto do código ficar semelhante ao da saída
        printf(  "                            MENU");
        printf("\n[1] - Adicionar novo contato  | [2] - Exibir todos os contatos");
        printf("\n[3] - Buscar contato [Codigo] | [4] - Buscar contato [Nome]");
        printf("\n[5] - Editar contato          | [6] - Remover contato");
        printf("\n[0] - Sair");
        printf("\nNumero de contatos: %d\n", tamanhoLista(li));

        printf("\nEntrada: ");
        scanf(" %d", &option); // Lê a opção do menu

        switch(option){
            case 1: // Adicionar novo contato
                printf("\nNOVO CONTATO");
                printf("\nCodigo: ");
                x = scanf("%d", &novo_contato.codigo);
                // Verifica se já existe um contato com esse código
                if(consultaCodigo(li, novo_contato.codigo, &consulta_contato)){
                    printf("\nJa exite um cliente com esse codigo na lista.\n");
                    break;
                }
                // Coleta dados para o novo contato
                novo_contato = coletaDados(novo_contato.codigo);
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
                    scanf("%d", &codigo); // Insere código para a consulta
                    x = consultaCodigo(li, codigo, &consulta_contato);
                    if(x){
                        // Se encontrar
                        imprimirContato(consulta_contato);
                        break;
                    }else{
                        printf("\nCodigo nao encontrado.");

                        while(1){
                            printf("\nRealizar uma nova busca? [1] SIM | [0] NAO: ");
                            scanf("%d", &option);
                            // Verifica entradas válidas pra sair do loop
                            if(option == 1 || option == 0){
                                break;
                            }
                            printf("\nEntrada invalida!\n");
                        }

                        if(option == 0){
                            // Coloca option para um valor diferente de 0
                            option = OPCAO_NULA;
                            break; // Sair do loop
                        }
                    }
                }while(1);
                break;

            case 4: // Buscar contato [Nome]
                do{
                    printf("Buscar contato por nome: ");
                    getchar(); // Limpeza de buffer
                    fgets(name, sizeof(name) - 1, stdin);
                    name[strcspn(name, "\n")] = '\0';  // Remove o '\n' da string, se presente

                    x = consultaNome(li, name);
                    if(x){
                        // Se tiver resultado na busca, encerra o loop
                        break;
                    }else{
                        printf("\nNome nao encontrado.");

                        while(1){
                            printf("\nRealizar uma nova busca? [1] SIM | [0] NAO: ");
                            scanf("%d", &option);
                            // Verifica entradas válidas pra sair do loop
                            if(option == 1 || option == 0){
                                break;
                            }
                            printf("\nEntrada invalida!\n");
                        }

                        if(option == 0){
                            // Coloca option para um valor diferente de 0
                            option = OPCAO_NULA;
                            break;
                        }
                    }
                }while(1);
                break;

            case 5: // Editar contato
                printf("\nEditar contato de codigo: ");
                scanf("%d", &codigo);
                // Verifica se há contato com o código inserido
                x = consultaCodigo(li, codigo, &consulta_contato);
                if(x){
                    // Imprime o contato a ser editado
                    imprimirContato(consulta_contato);

                    while(1){
                        // Confirmação para edição
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
                            // Coloca option para um valor diferente de 0
                            option = OPCAO_NULA;
                            break; // Para sair do loop

                        }else{
                            printf("\nEntrada invalida!\n");
                        }
                    }

                }else{
                    // Se a consulta falhar
                    printf("\nCodigo nao encontrado.");
                }
                break;

            case 6: // Remover contato
                do{
                    printf("Remover contato de codigo: ");
                    scanf("%d", &codigo);
                    x = consultaCodigo(li, codigo, &consulta_contato);
                    // Verifica se há contato com o código inserido
                    if(x){
                        imprimirContato(consulta_contato);
                        // Confirmação para exclusão
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
                            // Coloca option para um valor diferente de 0
                            option = OPCAO_NULA;
                            break;

                        }else{
                            printf("\nEntrada invalida!\n");
                        }

                    }else{
                        printf("\nCodigo nao encontrado.\n");
                        break;
                    }
                }while(1);
                break;

            case 0: // REncerrar programa
                break;

            default: // Entradas inválidas
                printf("\nEntrada invalida! Insira novamente...\n");
                break;
        }
        system("PAUSE");
    }while(option != 0); // Encerra o loop ao inserir a opção "Sair"

    salvaContatos(li, "contatos.txt");
    apagaLista(li);  // Liberando a memória
    printf("\nPrograma encerrado!\n");
    return 0;
}
