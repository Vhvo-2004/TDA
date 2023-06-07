#include<stdio.h>
#include<stdlib.h>
#include "ListaLigada.h"

int main() {
    LISTA a;
    REGISTRO novo_aluno = criarAluno(123, "Joao", 20);
    bool t,k;
    inicializarLista(&a);
    LerLista(&a);
    ExibirLista(&a);
    printf("Tamanho da lista: %d\n", tamanho(&a));
    lista_cheia(&a);
    t=inserirElemento(&a, novo_aluno);
    ExibirLista(&a);
    alterarMatricula(&a,123,8);
    ExibirLista(&a);
   k= excluirAluno(&a,8);
    ExibirLista(&a);
    return 0;
}

