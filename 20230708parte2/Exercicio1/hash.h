#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASH_H
#define HASH_H

#define N 101

typedef struct {
    int cod;
    char* nome;
    char* cpf;
    int idade;
    int disp;
} PACIENTE;

typedef PACIENTE* TB_HASH[N];
void excluir_paciente(TB_HASH tab,int cod);
int m_hash(int cod);
int inserir(TB_HASH tab, PACIENTE pac);
void inicializahash(TB_HASH tab);
void mostrarhash(TB_HASH tab);
PACIENTE* busca(TB_HASH tab, int cod);

#endif
