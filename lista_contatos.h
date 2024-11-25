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

Lista *criaLista();

void abortaPrograma();

void apagaLista(Lista *li); //Essa função deve ser a última a ser chamada pelo main()

int tamanhoLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int insereOrdenado(Lista *li, ALUNO al);

int removeOrdenado(Lista *li, int mat);

int consultaPosicao(Lista *li, int posicao, ALUNO *al);

int consultaMatricula(Lista *li, int mat, ALUNO *al);

ALUNO coletar_dados_aluno();

