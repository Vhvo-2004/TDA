#include <stdio.h>
#include <stdlib.h>
#include "LDL2.h"

int main() {
    Lista* p1 = criarLista();
    Lista* p2 = criarLista();

    inserirOrdenado(p1, 3, 5);
    inserirOrdenado(p1, 2, 1);
    inserirOrdenado(p1, -1, 0);

    inserirOrdenado(p2, 6, 1);
    inserirOrdenado(p2, 12, 0);

    printf("Polinômio P1: ");
    exibirPolinomio(p1);

    printf("Polinômio P2: ");
    exibirPolinomio(p2);

    Lista* soma = somaPolinomios(p1, p2);
    printf("Soma dos polinômios: ");
    exibirPolinomio(soma);

    destruirLista(p1);
    destruirLista(p2);
    destruirLista(soma);

    return 0;
}

