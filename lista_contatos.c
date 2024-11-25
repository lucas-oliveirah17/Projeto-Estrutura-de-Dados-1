// Arquivo lista_contatos.c
#include <stdio.h>
#include <stdlib.h>
#include "lista_contatos.h"

struct elemento{
    CLIENTE dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    /*Armazenar� o endere�o do in�cio do bloco alocado,
    e ser� devolvido ao main()*/
    li = (Lista*) malloc(sizeof(Lista));
    /*Se aloca��o ok, preenche o conte�do que foi
    alocado com NULL*/
    if(li != NULL) {
        *li = NULL;
    }
    return li;
}

void abortaPrograma(){
    /*Em cada fun��o que acessa diretamente a lista, �
    absolutamente necess�rio testar se a mesma foi
    alocada*/
    printf("ERRO! Lista nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

void apagaLista(Lista *li){
    /*Recebe o endere�o da lista na mem�ria*/
    /*Lista ser� v�lida se li for diferente de NULL*/
    if(li != NULL){
        ELEM *no;
        /*Enquanto o primeiro elemento da lista n�o
        for diferente de NULL, a lista n�o estar� vazia.
        while: executa este conjunto de instru��es, at�
        que a cabe�a da lista aponte para NULL, e assim a
        lista estar� vazia.*/
        while((*li) != NULL){
            no = *li;
            /*Inicio da lista, aponta para pr�ximo elemento
            da lista*/
            *li = (*li)->prox;
            free(no);
        }
        /*Ao final, libera a cabe�a da lista (ponteiro especial)
        que aponta para o �nicio*/
        free(li);
    }
}

int tamanhoLista(Lista *li) {
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    /*n� � um ponteiro auxiliar e recebe o 1� elemento da
    Lista. n� foi criado para se preservar o inicio da
    lista, porque se andarmos com a cabe�a da lista,
    perderemos seu endere�o de in�cio. Sempre percorremos
    uma lista com elementos auxiliares, para n�o perdermos
    informa��es*/
    ELEM *no = *li;
    while(no != NULL){
        /*Enquanto n� n�o for NULL, incrementa o acumulador e
        se desloca para o pr�ximo n�.*/
        acum++;
        no = no->prox;
    }
    /*acum retorna a quantidade de elementos que existem
    na lista.*/
    return acum;
}

int listaCheia(Lista *li){
    /*� Em Listas Ligadas (din�micas encadeadas), n�o
    existe o conceito de lista cheia.
    Esta fun��o � mantida apenas por quest�es de
    compatibilidade com outras estruturas do tipo
    Lista.*/
    if(li == NULL){
        abortaPrograma();
    }
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        /*Se a lista n�o foi alocada, ou seja, li for igual
        a NULL o programa � ent�o abortado.*/
        abortaPrograma();
    }
    /*Se no endere�o que *li aponta, estiver armazenado NULL,
    ainda n�o existe nenhum elemento dentro da lista.*/
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int insereOrdenado(Lista *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return al.matricula;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        /*Insere se estiver na primeira posi��o*/
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            /*Insere em qualquer outra posi��o*/
            no->prox = ant->prox;
            ant->prox = no;
        }
        return al.matricula;
    }
}

int removeOrdenado(Lista *li, int mat){
    int matricula;
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *ant, *no = *li;
    /*N�o � necess�rio testar se a lista est� vazia para
    remover, o while faz esse tratamento, quando testa se
    no != NULL.*/
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    /*Se o n� est� parado na primeira posi��o, significa que
    a lista n�o foi percorrida. � o caso em que o elemento a
    ser removido � menor do que todos os outros na lista.*/
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    /*Remove no in�nicio, meio e fim.*/
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
    /*Percorre toda a lista, incrementando 1 para cada elemento
    pesquisado*/
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        /*Se n� for igual a NULL, o elemento n�o foi encontrado
        (posi��o n�o existe), ou lista estava vazia.*/
        return 0;
    }else{
        /*Mas se n� � diferente de NULL, siginifica que n� est�
        apontando para o elemento procurado, e ent�o, � s� copiar
        os dados do elemento.*/
        *al = no->dados;
        return 1;
    }
}

int consultaMatricula(Lista *li, int mat, ALUNO *al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = *li;
    /*PEnquanto n� for diferente de NULL, e a matricula na lista
    for diferente da matricula que procuro...*/
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        /*Se ao final da busca, n� for igual a NULL< significa que
        o elemento buscado n�o existe na lista, ou a mesma est�
        vazia*/
        return 0;
    }else{
        /*Se n� diferente de NULL, significa que o elemento buscado
        foi encontrado, e ent�o, � s� copiar seu conte�do*/
        *al = no->dados;
        return 1;
    }
}

ALUNO coletar_dados_aluno(){
    ALUNO al;
    printf("\nMatr�cula: ");
    scanf("%d", &al.matricula);

    do{
        printf("Nota 1: ");
        scanf("%f", &al.n1);
        if(al.n1 < 0 || al.n1 > 10)
            printf("Valor inv�lido! Somente valor de 0 � 10 s�o aceitos.\n");
    }while(!(al.n1 >= 0 && al.n1 <= 10));

    do{
        printf("Nota 2: ");
        scanf("%f", &al.n2);
        if(al.n2 < 0 || al.n2 > 10)
            printf("Valor inv�lido! Somente valor de 0 � 10 s�o aceitos.\n");
    }while(!(al.n2 >= 0 && al.n2 <= 10));

    do{
        printf("Nota 3: ");
        scanf("%f", &al.n3);
        if(al.n3 < 0 || al.n3 > 10)
            printf("Valor inv�lido! Somente valor de 0 � 10 s�o aceitos.\n");
    }while(!(al.n3 >= 0 && al.n3 <= 10));
    return al;
}
