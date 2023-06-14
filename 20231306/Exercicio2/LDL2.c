#include <stdio.h>
#include <stdlib.h>
#include "LDL2.h"

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void destruirLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

void inserirOrdenado(Lista* lista, int coeficiente, int expoente) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->coeficiente = coeficiente;
    novoNo->expoente = expoente;

    if (lista->inicio == NULL || expoente > lista->inicio->expoente) {
        novoNo->prox = lista->inicio;
        lista->inicio = novoNo;
    } else {
        No* atual = lista->inicio;
        while (atual->prox != NULL && expoente < atual->prox->expoente) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}

Lista* somaPolinomios(Lista* p1, Lista* p2) {
    Lista* resultado = criarLista();
    No* termo1 = p1->inicio;
    No* termo2 = p2->inicio;

    while (termo1 != NULL && termo2 != NULL) {
        if (termo1->expoente > termo2->expoente) {
            inserirOrdenado(resultado, termo1->coeficiente, termo1->expoente);
            termo1 = termo1->prox;
        } else if (termo2->expoente > termo1->expoente) {
            inserirOrdenado(resultado, termo2->coeficiente, termo2->expoente);
            termo2 = termo2->prox;
        } else {
            int coeficienteSoma = termo1->coeficiente + termo2->coeficiente;
            if (coeficienteSoma != 0) {
                inserirOrdenado(resultado, coeficienteSoma, termo1->expoente);
            }
            termo1 = termo1->prox;
            termo2 = termo2->prox;
        }
    }

    while (termo1 != NULL) {
        inserirOrdenado(resultado, termo1->coeficiente, termo1->expoente);
        termo1 = termo1->prox;
    }

    while (termo2 != NULL) {
        inserirOrdenado(resultado, termo2->coeficiente, termo2->expoente);
        termo2 = termo2->prox;
    }

    return resultado;
}

void exibirPolinomio(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%dx^%d ", atual->coeficiente, atual->expoente);
        if (atual->prox != NULL) {
            printf("+ ");
        }
        atual = atual->prox;
    }
    printf("\n");
}

