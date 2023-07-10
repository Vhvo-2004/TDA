#ifndef HASH_H
#define HASH_H

#define N 101

typedef struct {
    int cod;
    char* nome;
    char* cpf;
    int idade;
} PACIENTE;

typedef struct node {
    PACIENTE pac;
    struct node* next;
} NODE;

typedef NODE* TB_HASH[N];

int m_hash(int cod);
void inicializahash(TB_HASH tab);
void inserir(TB_HASH tab, PACIENTE pac);
void mostrarhash(TB_HASH tab);
void excluir(TB_HASH tab, int cod);
PACIENTE* busca(TB_HASH tab, int cod);

#endif

