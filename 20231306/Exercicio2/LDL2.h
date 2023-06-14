#ifndef LDL_2_H
#define LDL_2_H

typedef struct No {
    int coeficiente;
    int expoente;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} Lista;

Lista* criarLista();
void destruirLista(Lista* lista);
void inserirOrdenado(Lista* lista, int coeficiente, int expoente);
Lista* somaPolinomios(Lista* p1, Lista* p2);
void exibirPolinomio(Lista* lista);

#endif
