// Arquivo lista_contatos.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        printf("|************************************************************************\n");
        printf("|*|Codigo: %d\n", li->dados.codigo);
        printf("|*|Nome: %s", li->dados.nome);
        printf("|*|Empresa: %s", li->dados.empresa);
        printf("|*|Departemento: %s", li->dados.departamento);
        printf("|*|Telefone: %s", li->dados.telefone);
        printf("|*|Celular: %s", li->dados.celular);
        printf("|*|E-mail: %s", li->dados.email);
        printf("|************************************************************************\n");
        li = li->prox;
    }
}

void imprimirContato(CLIENTE cl){ // Rotina para a impressão das informações de contato
    printf("\n|************************************************************|");
    printf("\n Codigo: %d", cl.codigo);
    printf("\n Nome: %s", cl.nome);
    printf(" Empresa: %s", cl.empresa);
    printf(" Departamento: %s", cl.departamento);
    printf(" Telefone: %s", cl.telefone);
    printf(" Celular: %s", cl.celular);
    printf(" Email: %s", cl.email);
    printf("|************************************************************|\n");
};

void salvaContatos(Lista *li, const char *nomeArquivo) {
    if (li == NULL) {
        printf("Erro na lista! LI=NULL\n");
        abortaPrograma();
    }

    // Abre o arquivo no modo leitura ("r") para verificar se já existem contatos com o mesmo código
    FILE *arquivoLeitura = fopen(nomeArquivo, "r");
    if (arquivoLeitura == NULL) {
        // Caso o arquivo não exista, podemos continuar criando o arquivo no modo de escrita
        arquivoLeitura = fopen(nomeArquivo, "w");
        if (arquivoLeitura == NULL) {
            printf("Erro ao abrir o arquivo para leitura e escrita!\n");
            return;
        }
    }

    // Lista para armazenar os códigos dos contatos já salvos
    int codigosSalvos[1000]; // Supondo que nunca teremos mais de 1000 contatos
    int numCodigosSalvos = 0; // Contador de códigos salvos

    // Lê os dados existentes no arquivo e armazena os códigos na lista
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), arquivoLeitura)) {
        int codigo;
        // Lê o código do contato
        sscanf(buffer, "%d", &codigo);
        codigosSalvos[numCodigosSalvos++] = codigo;  // Armazena o código
    }

    fclose(arquivoLeitura);

    // Abre o arquivo novamente, desta vez para escrita no modo de acréscimo ("a")
    FILE *arquivoEscrita = fopen(nomeArquivo, "a");
    if (arquivoEscrita == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    ELEM *atual = *li;

    // Escreve cada contato no arquivo com os campos separados por ponto e vírgula
    while (atual != NULL) {
        int codigoAtual = atual->dados.codigo;
        int existe = 0;

        // Verifica se o código já foi salvo antes
        for (int i = 0; i < numCodigosSalvos; i++) {
            if (codigosSalvos[i] == codigoAtual) {
                existe = 1;  // Contato com esse código já foi salvo
                break;
            }
        }

        if (!existe) {
            // Adiciona o código atual à lista de códigos salvos
            codigosSalvos[numCodigosSalvos++] = codigoAtual;

            // Remover o '\n' do final das strings antes de escrever
            if (atual->dados.nome[strlen(atual->dados.nome) - 1] == '\n') {
                atual->dados.nome[strlen(atual->dados.nome) - 1] = '\0';
            }
            if (atual->dados.empresa[strlen(atual->dados.empresa) - 1] == '\n') {
                atual->dados.empresa[strlen(atual->dados.empresa) - 1] = '\0';
            }
            if (atual->dados.departamento[strlen(atual->dados.departamento) - 1] == '\n') {
                atual->dados.departamento[strlen(atual->dados.departamento) - 1] = '\0';
            }
            if (atual->dados.telefone[strlen(atual->dados.telefone) - 1] == '\n') {
                atual->dados.telefone[strlen(atual->dados.telefone) - 1] = '\0';
            }
            if (atual->dados.celular[strlen(atual->dados.celular) - 1] == '\n') {
                atual->dados.celular[strlen(atual->dados.celular) - 1] = '\0';
            }
            if (atual->dados.email[strlen(atual->dados.email) - 1] == '\n') {
                atual->dados.email[strlen(atual->dados.email) - 1] = '\0';
            }

            // Usando fprintf para formatar a escrita no arquivo com ponto e vírgula
            fprintf(arquivoEscrita, "%d;%s;%s;%s;%s;%s;%s\n",
                    atual->dados.codigo,
                    atual->dados.nome,
                    atual->dados.empresa,
                    atual->dados.departamento,
                    atual->dados.telefone,
                    atual->dados.celular,
                    atual->dados.email);
        }
        atual = atual->prox;
    }

    fclose(arquivoEscrita);
    printf("\nContatos salvos com sucesso no arquivo '%s'.\n", nomeArquivo);
}


void carregaContatos(Lista *li, const char *nomeArquivo) {
    if (li == NULL) {
        printf("Erro na lista! LI=NULL\n");
        abortaPrograma();
    }

    printf("\nCarregando Contatos\n");
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado, nenhum contato foi carregado.\n");
        return;
    }

    CLIENTE cl;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), arquivo)) {
        // Limpa qualquer possível lixo no buffer, incluindo quebras de linha extras
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove o \n no final da string

        // Lê os dados do arquivo separados por ';'
        int camposLidos = sscanf(buffer, "%d;%99[^;];%99[^;];%99[^;];%99[^;];%99[^;];%99[^\n]",
                                  &cl.codigo,
                                  cl.nome,
                                  cl.empresa,
                                  cl.departamento,
                                  cl.telefone,
                                  cl.celular,
                                  cl.email);

        // Verifica se todos os campos foram lidos corretamente
        if (camposLidos != 7) {
            printf("Erro ao ler a linha do arquivo: '%s'. Campos lidos: %d\n", buffer, camposLidos);
            continue;  // Ignora a linha com erro e continua com a próxima
        }

        // Adiciona o '\n' no final de cada string lida
        if (cl.nome[strlen(cl.nome) - 1] != '\n') {
            strcat(cl.nome, "\n");
        }
        if (cl.empresa[strlen(cl.empresa) - 1] != '\n') {
            strcat(cl.empresa, "\n");
        }
        if (cl.departamento[strlen(cl.departamento) - 1] != '\n') {
            strcat(cl.departamento, "\n");
        }
        if (cl.telefone[strlen(cl.telefone) - 1] != '\n') {
            strcat(cl.telefone, "\n");
        }
        if (cl.celular[strlen(cl.celular) - 1] != '\n') {
            strcat(cl.celular, "\n");
        }
        if (cl.email[strlen(cl.email) - 1] != '\n') {
            strcat(cl.email, "\n");
        }

        // Insere os dados lidos de forma ordenada
        insereOrdenado(li, cl);
    }

    fclose(arquivo);
    printf("\nContatos carregados do arquivo '%s'.\n", nomeArquivo);
}


/*
int tamanhoLista(Lista *li) {
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    //nó é um ponteiro auxiliar e recebe o 1º elemento da
    //Lista. nó foi criado para se preservar o inicio da
    //lista, porque se andarmos com a cabeça da lista,
    //perderemos seu endereço de início. Sempre percorremos
    //uma lista com elementos auxiliares, para não perdermos
    //informações
    ELEM *no = *li;
    while(no != NULL){
        //Enquanto nó não for NULL, incrementa o acumulador e
        //se desloca para o próximo nó.
        acum++;
        no = no->prox;
    }
    //acum retorna a quantidade de elementos que existem
    //na lista.
    return acum;
}

int listaCheia(Lista *li){
    //Em Listas Ligadas (dinâmicas encadeadas), não
    //existe o conceito de lista cheia.
    //Esta função é mantida apenas por questões de
    //compatibilidade com outras estruturas do tipo
    //Lista.
    if(li == NULL){
        abortaPrograma();
    }
    return 0;
}

int removeOrdenado(Lista *li, int mat){
    int matricula;
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *ant, *no = *li;
    //Não é necessário testar se a lista está vazia para
    //remover, o while faz esse tratamento, quando testa se
    //no != NULL.
    while(no != NULL && no->dados.matricula != mat){
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
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int consultaPosicao(Lista *li, int posicao, ALUNO *al){
    if(li == NULL){
        abortaPrograma();
    }
    if(posicao <= 0){
        return 0;
    }
    ELEM *no = *li;
    int i = 1;
    //Percorre toda a lista, incrementando 1 para cada elemento
    //pesquisado
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        //Se nó for igual a NULL, o elemento não foi encontrado
        //(posição não existe), ou lista estava vazia.
        return 0;
    }else{
        //Mas se nó é diferente de NULL, siginifica que nó está
        //apontando para o elemento procurado, e então, é só copiar
        //os dados do elemento.
        *al = no->dados;
        return 1;
    }
}

ALUNO coletar_dados_aluno(){
    ALUNO al;
    printf("\nMatrícula: ");
    scanf("%d", &al.matricula);

    do{
        printf("Nota 1: ");
        scanf("%f", &al.n1);
        if(al.n1 < 0 || al.n1 > 10)
            printf("Valor inválido! Somente valor de 0 à 10 são aceitos.\n");
    }while(!(al.n1 >= 0 && al.n1 <= 10));

    do{
        printf("Nota 2: ");
        scanf("%f", &al.n2);
        if(al.n2 < 0 || al.n2 > 10)
            printf("Valor inválido! Somente valor de 0 à 10 são aceitos.\n");
    }while(!(al.n2 >= 0 && al.n2 <= 10));

    do{
        printf("Nota 3: ");
        scanf("%f", &al.n3);
        if(al.n3 < 0 || al.n3 > 10)
            printf("Valor inválido! Somente valor de 0 à 10 são aceitos.\n");
    }while(!(al.n3 >= 0 && al.n3 <= 10));
    return al;
}
*/
