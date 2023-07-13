#ifndef HASH_H
#define HASH_H

#define N 9
#define M 11


typedef struct node {
    int pac;
    struct node* next;
} NODE;

typedef NODE* TB_HASH[101];

int m_hash1(int cod);
int m_hash2(int cod);
void inicializahash(TB_HASH tab,int tam);
void inserir(TB_HASH tab, int pac,int (*func)(int));
void mostrarhash(TB_HASH tab,int chave);


#endif

