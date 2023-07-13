#include "hash2.1.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarTabela(TB_HASH tabela) {
    for (int i = 0; i < 11; i++) {
        tabela[i] = NULL;
    }
}

int sondagemLinear(int chave, int i) {
    return (chave + i) % 11;
}

int sondagemQuadratica(int chave, int i) {
    return (chave + i * i) % 11;
}

int sondagemQuadraticaFator2(int chave, int i) {
    return (chave + 2 * i + i * i) % 11;
}

int hashDuplo(int chave, int i) {
    int h1 = chave % 11;
    int h2 = 7 - (chave % 7);
    return (h1 + i * h2) % 11;
}

void inserirChave(TB_HASH tabela, int chave, int (*funcaoHash)(int, int),int* cont) {
    int i = 0;
    int indice;
    do {
    	if(i!=0){
    	*cont=*cont+1;
    }
        indice = funcaoHash(chave, i);
        i++;
    } while (tabela[indice] != NULL);
    PACIENTE* novoPaciente = (PACIENTE*)malloc(sizeof(PACIENTE));
    novoPaciente->chave = chave;
    tabela[indice] = novoPaciente;
    
}

void imprimirTabela(TB_HASH tabela) {
    for (int i = 0; i < 11; i++) {
        if (tabela[i] != NULL) {
            printf("%d ", tabela[i]->chave);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

void destruirTabela(TB_HASH tabela) {
    for (int i = 0; i < 11; i++) {
        if (tabela[i] != NULL) {
            free(tabela[i]);
        }
    }
}

