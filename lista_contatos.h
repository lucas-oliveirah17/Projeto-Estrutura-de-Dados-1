// Arquivo lista_contatos.h
typedef struct cliente{
    int codigo;
    char nome[50];
    char empresa[50];
    char departamento[20];
    char telefone[20];
    char celular[20];
    char email[50];
}CLIENTE;

/*Ponteiro apontado pelo ponteiro da função main*/
typedef struct elemento* Lista;


Lista *criaLista(); //Aloca memória para a lista

void apagaLista(Lista *li); //Função que destrói a lista alocada.

void abortaPrograma(); //Aborta o programa se lista não alocada

int listaVazia(Lista *li); // Verifica se lista está vazia

int insereOrdenado(Lista *li, CLIENTE cl); // Insere ordenado, um novo contato

int consultaCodigo(Lista *li, int cod, CLIENTE *cl); // Consulta por código na lista

/*
int tamanhoLista(Lista *li);

int listaCheia(Lista *li);





int removeOrdenado(Lista *li, int mat);

int consultaPosicao(Lista *li, int posicao, ALUNO *al);



ALUNO coletar_dados_aluno();
*/
