#include<stdio.h>
#include<stdlib.h>
#include "LDL.h"

void inicializarLista(No** inicio, int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    *inicio = novoNo;
}

void inserirNoInicio(No** inicio, int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = *inicio;
    novoNo->ant = NULL;
    if (*inicio != NULL) {
        (*inicio)->ant = novoNo;
    }
    *inicio = novoNo;
}

No* removerNo(No** inicio, No* no) {
    if (no->ant != NULL) {
        no->ant->prox = no->prox;
    } else {
        *inicio = no->prox;
    }
    if (no->prox != NULL) {
        no->prox->ant = no->ant;
    }
    No* proximo = no->prox;
    free(no);
    return proximo;
}

No* encontrarMaiorNo(No* inicio) {
    No* maior = inicio;
    No* atual = inicio;
    while (atual != NULL) {
        if (atual->valor > maior->valor) {
            maior = atual;
        }
        atual = atual->prox;
    }
    
    return maior;
}

No* ordenarLista(No** L){
    No* K = NULL;
    while (*L != NULL) {
        No* maiorNo = *L;
        No* atual = *L;

        // Encontra o nó com o maior valor
        while (atual != NULL) {
            if (atual->valor > maiorNo->valor) {
                maiorNo = atual;
            }
            atual = atual->prox;
        }

        // Remove o nó com o maior valor da lista original
        if (maiorNo->ant != NULL) {
            maiorNo->ant->prox = maiorNo->prox;
        } else {
            *L = maiorNo->prox;
        }
        if (maiorNo->prox != NULL) {
            maiorNo->prox->ant = maiorNo->ant;
        }

        // Insere o nó no início da lista ordenada K
        if (K == NULL) {
            K = maiorNo;
            K->prox = NULL;
            K->ant = NULL;
        } else {
            maiorNo->prox = K;
            maiorNo->ant = NULL;
            K->ant = maiorNo;
            K = maiorNo;
        }
    }
    return K;
}


void exibirLista(No* inicio) {
    printf("Lista: ");
    No* atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

