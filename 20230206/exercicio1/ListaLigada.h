#ifndef ListaLigada_H
#define ListaLigada_H

#define MAX 7
#define MAX1 100
#define INVALIDO -1
typedef int TIPOCHAVE;
typedef struct{
    TIPOCHAVE matricula;
    char nome[50];
    int idade;
} REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX1];
    int inicio;
    int dispo;
} LISTA;
void alterarMatricula(LISTA* l, TIPOCHAVE matricula, TIPOCHAVE novaMatricula);
int obterNo(LISTA* m);
void alocarNo(LISTA* l, int i);
void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void ExibirLista(LISTA* l);
void LerLista(LISTA* l);
void lista_cheia(LISTA* l);
bool inserirElemento(LISTA *l, REGISTRO novo_aluno);
bool excluirAluno(LISTA* l, int matricula);
REGISTRO criarAluno(int matricula, const char* nome, int idade);
#endif

