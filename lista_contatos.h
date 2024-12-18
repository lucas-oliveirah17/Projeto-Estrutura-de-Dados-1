// Arquivo lista_contatos.h
#define OPCAO_NULA -1

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

void apresentaClientes(Lista li);

void imprimirContato(CLIENTE cl); // Rotina para a impressão das informações de contato


void salvaContatos(Lista *li, const char *nomeArquivo);

void carregaContatos(Lista *li, const char *nomeArquivo);

int removeOrdenado(Lista *li, int cod); // Remove contato por código fornecido

CLIENTE coletaDados(int cod); // Função para coleta de dados

int editaContato(Lista *li, int cod); // Função para editar contato

int consultaNome(Lista *li, char name[50]); // Função para consulta por nome

void toUpperString(char *string); // Função para converter todos os caracteres em maiusculo na string

int tamanhoLista(Lista *li); // Função para verificar tamanho da lista
