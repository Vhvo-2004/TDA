#ifndef LDL_H
#define LDL_H

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

void inicializarLista(No** inicio, int valor);
void inserirNoInicio(No** inicio, int valor);
No* removerNo(No** inicio, No* no);
No* encontrarMaiorNo(No* inicio);
No* ordenarLista(No** L);
void exibirLista(No* inicio);

#endif

