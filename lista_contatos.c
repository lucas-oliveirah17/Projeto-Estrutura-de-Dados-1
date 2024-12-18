// Arquivo lista_contatos.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista_contatos.h"

struct elemento{
    CLIENTE dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    //Armazenará o endereço do início do bloco alocado, e será
    //devolvido ao main()
    li = (Lista*) malloc(sizeof(Lista));
    //Se alocação ok, preenche o conteúdo que foi alocado com NULL
    if(li == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        abortaPrograma(); // Esse erro é gerado quando a alocação falha
    }
    if(li != NULL) {
        *li = NULL;
    }
    return li;
}

void apagaLista(Lista *li){
    //Recebe o endereço da lista na memória Lista será válida se li
    //for diferente de NULL
    if(li != NULL){
        ELEM *no;
        //Enquanto o primeiro elemento da lista não for diferente de
        //NULL, a lista não estará vazia. while: executa este conjunto
        //de instruções, até que a cabeça da lista aponte para NULL, e
        //assim a lista estará vazia.
        while((*li) != NULL){
            no = *li;
            //Inicio da lista, aponta para próximo elemento da lista
            *li = (*li)->prox;
            free(no);
        }
        //Ao final, libera a cabeça da lista (ponteiro especial) que
        //aponta para o ínicio
        free(li);
    }
}

void abortaPrograma(){
    //Em cada função que acessa diretamente a lista, é absolutamente
    //necessário testar se a mesma foi alocada
    printf("ERRO! Lista nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

int listaVazia(Lista *li){
    if(li == NULL){
        //Se a lista não foi alocada, ou seja, li for igual a NULL o
        //programa é então abortado.
        abortaPrograma();
    }
    //Se no endereço que *li aponta, estiver armazenado NULL, ainda não
    //existe nenhum elemento dentro da lista.
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int insereOrdenado(Lista *li, CLIENTE cl){
    if(li == NULL){ // Verifica se lista foi alocada
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM)); //Aloca um no auxiliar
    if(no == NULL){ //Interrompe o programa se alocação falha
        return 0;
    }
    no->dados = cl;
    if(listaVazia(li)){ // Verifica se lista está vazia
        no->prox = (*li);
        *li = no;
        return cl.codigo;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.codigo < cl.codigo){
            ant = atual;
            atual = atual->prox;
        }
        //Insere se estiver na primeira posição
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            //Insere em qualquer outra posição
            no->prox = ant->prox;
            ant->prox = no;
        }
        return cl.codigo;
    }
}

int consultaCodigo(Lista *li, int cod, CLIENTE *cl){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = *li;
    //PEnquanto nó for diferente de NULL, e a matricula na lista for diferente
    //da matricula que procuro...
    while(no != NULL && no->dados.codigo != cod){
        no = no->prox;
    }
    if(no == NULL){
        //Se ao final da busca, nó for igual a NULL< significa que o elemento
        // buscado não existe na lista, ou a mesma está vazia
        return 0;
    }else{
        //Se nó diferente de NULL, significa que o elemento buscado foi
        //encontrado, e então, é só copiar seu conteúdo
        *cl = no->dados;
        return 1;
    }
}

void apresentaClientes(Lista li){
    // Verifica se a lista esta vazia
    if(li == NULL){
        printf("\n** Sem Contatos Existentes!! **\n\n");
        return ;
    }

    printf("Listagem Total dos Usuarios Cadastrados:\n");

    // Apresenta os clientes cadastrados
    while(li != NULL){
        imprimirContato(li->dados);
        li = li->prox;
    }
}

void imprimirContato(CLIENTE cl){ // Rotina para a impressão das informações de contato
    printf("\n|************************************************************|");
    printf("\n Codigo: %d", cl.codigo);
    printf("\n Nome: %s", cl.nome);
    printf("\n Empresa: %s", cl.empresa);
    printf("\n Departamento: %s", cl.departamento);
    printf("\n Telefone: %s", cl.telefone);
    printf("\n Celular: %s", cl.celular);
    printf("\n Email: %s", cl.email);
    printf("\n|************************************************************|\n");
};

void salvaContatos(Lista *li, const char *nomeArquivo) {
    if (li == NULL) {
        printf("Erro na lista! LI=NULL\n");
        abortaPrograma();
    }

    // Abre o arquivo para escrita no modo binário ("wb")
    FILE *arquivoEscrita = fopen(nomeArquivo, "wb");
    if (arquivoEscrita == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    ELEM *atual = *li;

    // Escreve cada contato no arquivo binário
    while (atual != NULL) {
        // Escreve os dados do cliente diretamente no arquivo binário
        fwrite(&atual->dados, sizeof(CLIENTE), 1, arquivoEscrita);
        atual = atual->prox;
    }

    fclose(arquivoEscrita);
    printf("\nContatos salvos com sucesso no arquivo binario '%s'.\n", nomeArquivo);
}


void carregaContatos(Lista *li, const char *nomeArquivo) {
    if (li == NULL) {
        printf("Erro na lista! LI=NULL\n");
        abortaPrograma();
    }

    printf("\nCarregando Contatos\n");
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado, nenhum contato foi carregado.\n");
        return;
    }

    CLIENTE cl;

    // Lê os dados do arquivo binário e os insere na lista
    while (fread(&cl, sizeof(CLIENTE), 1, arquivo) == 1) {
        // Insere os dados lidos de forma ordenada na lista
        insereOrdenado(li, cl);
    }

    fclose(arquivo);
    printf("\nContatos carregados do arquivo binario '%s'.\n", nomeArquivo);
}

int removeOrdenado(Lista *li, int cod){
    int codigo;
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *ant, *no = *li;
    //Não é necessário testar se a lista está vazia para
    //remover, o while faz esse tratamento, quando testa se
    //no != NULL.
    while(no != NULL && no->dados.codigo != cod){
        ant = no;
        no = no->prox;
    }
    //Se o nó está parado na primeira posição, significa que
    //a lista não foi percorrida. É o caso em que o elemento a
    //ser removido é menor do que todos os outros na lista.
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    //Remove no inínicio, meio e fim.
    codigo = no->dados.codigo;
    free(no);
    return codigo;
}

CLIENTE coletaDados(int cod) {
    CLIENTE contato;
    contato.codigo = cod;

    printf("Nome: ");
    getchar();  // Limpeza de buffer
    fgets(contato.nome, sizeof(contato.nome) - 1, stdin);
    toUpperString(contato.nome);
    contato.nome[strcspn(contato.nome, "\n")] = '\0';  // Remove o '\n' da string, se presente

    printf("Empresa: ");
    fgets(contato.empresa, sizeof(contato.empresa) - 1, stdin);
    contato.empresa[strcspn(contato.empresa, "\n")] = '\0';  // Remove o '\n' da string, se presente

    printf("Departamento: ");
    fgets(contato.departamento, sizeof(contato.departamento) - 1, stdin);
    contato.departamento[strcspn(contato.departamento, "\n")] = '\0';  // Remove o '\n' da string, se presente

    printf("Telefone: ");
    fgets(contato.telefone, sizeof(contato.telefone) - 1, stdin);
    contato.telefone[strcspn(contato.telefone, "\n")] = '\0';  // Remove o '\n' da string, se presente

    printf("Celular: ");
    fgets(contato.celular, sizeof(contato.celular) - 1, stdin);
    contato.celular[strcspn(contato.celular, "\n")] = '\0';  // Remove o '\n' da string, se presente

    printf("Email: ");
    fgets(contato.email, sizeof(contato.email) - 1, stdin);
    contato.email[strcspn(contato.email, "\n")] = '\0';  // Remove o '\n' da string, se presente

    return contato;
}

int editaContato(Lista *li, int cod){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = *li;
    //PEnquanto nó for diferente de NULL, e o codigo na lista for diferente
    //do codigo que procuro...
    while(no != NULL && no->dados.codigo != cod){
        no = no->prox;
    }
    if(no == NULL){
        //Se ao final da busca, nó for igual a NULL< significa que o elemento
        // buscado não existe na lista, ou a mesma está vazia
        return 0;
    }else{
        //Se nó diferente de NULL, significa que o elemento buscado foi
        //encontrado, e então, é só editar seu conteúdo

        no->dados = coletaDados(cod);
        //*cl = no->dados;
        return 1;
    }
}

int consultaNome(Lista *li, char *name){
    if(li == NULL){
        abortaPrograma();
    }
    toUpperString(name);
    ELEM *no = *li;
    //PEnquanto nó for diferente de NULL, e o nome na lista for diferente
    //do nome que procuro...
    while(no != NULL){
        if(strcmp(no->dados.nome, name) == 0){
             imprimirContato(no->dados);
        }
        no = no->prox;
    }
    if(no == NULL){
        //Se ao final da busca, nó for igual a NULL< significa que o elemento
        // buscado não existe na lista, ou a mesma está vazia
        return 0;
    }else{
        //Se nó diferente de NULL, significa que o elemento buscado foi
        //encontrado, e então, é só copiar seu conteúdo
        //*cl = no->dados;
        return 1;
    }
}

void toUpperString(char *string){
    while(*string && *string != '\0'){
        *string = toupper((unsigned char)*string);
        string++; // Avança para o próximo caractere
    }
}

int tamanhoLista(Lista *li) {
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    /*nó é um ponteiro auxiliar e recebe o 1º elemento da
    Lista. nó foi criado para se preservar o inicio da
    lista, porque se andarmos com a cabeça da lista,
    perderemos seu endereço de início. Sempre percorremos
    uma lista com elementos auxiliares, para não perdermos
    informações*/
    ELEM *no = *li;
    while(no != NULL){
        /*Enquanto nó não for NULL, incrementa o acumulador e
        se desloca para o próximo nó.*/
        acum++;
        no = no->prox;
    }
    /*acum retorna a quantidade de elementos que existem
    na lista.*/
    return acum;
}
