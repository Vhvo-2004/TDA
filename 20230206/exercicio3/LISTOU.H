#ifndef LISTA_H
#define LISTA_H

#define N 100

typedef struct {
    int l;
} REGISTRO;

typedef struct {
    REGISTRO reg;
    int proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO A[N];
    int disp;
    int inicio;
} LISTA_LIGADA_ESTATICA;

void inicializarLista(LISTA_LIGADA_ESTATICA* L);
void formar_lista(LISTA_LIGADA_ESTATICA* L);
void exibir_lista(LISTA_LIGADA_ESTATICA* L);
void copiar_lista(LISTA_LIGADA_ESTATICA* L1, LISTA_LIGADA_ESTATICA* L2);
void concatenar_listas(LISTA_LIGADA_ESTATICA* L1, LISTA_LIGADA_ESTATICA* L2, LISTA_LIGADA_ESTATICA* LC);
void intercalar_listas(LISTA_LIGADA_ESTATICA* L1, LISTA_LIGADA_ESTATICA* L2, LISTA_LIGADA_ESTATICA* LI);

#endif

