#include<stdio.h>
#include<stdlib.h>
#include "LDL.h"

int main() {
    No* L = NULL;
    inicializarLista(&L, 5);
    inserirNoInicio(&L, 2);
    inserirNoInicio(&L, 7);
    inserirNoInicio(&L, 3);
    inserirNoInicio(&L, 1);
    exibirLista(L);

    No* K = ordenarLista(&L);
    exibirLista(K);

    return 0;
}

