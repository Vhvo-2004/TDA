#ifndef LISTA_H
#define LISTA_H
#define N 5
typedef struct {
	int l;
	
}caracteristica;
typedef struct {
	caracteristica reg;
	int proximo;
	
}ELEMENTO;
typedef struct{
	ELEMENTO A[N];
	int disp;
	int inicio;
	
}LISTA_LIGADA_ESTATICA;
void formatar_lista(LISTA_LIGADA_ESTATICA* L,LISTA_LIGADA_ESTATICA* C);
void inicializarLista(LISTA_LIGADA_ESTATICA* L);
void formar_lista(LISTA_LIGADA_ESTATICA* L);
void exibir_lista(LISTA_LIGADA_ESTATICA* L);
#endif
