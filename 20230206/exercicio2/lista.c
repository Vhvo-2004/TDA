#include<stdio.h>
#include "lista.h"
#include<math.h>
#include<stdlib.h>

void inicializarLista(LISTA_LIGADA_ESTATICA* L){
	int i;
	for(i=0;i<N-1;i++){
		L->A[i].proximo=i+1;
	}
	L->A[N-1].proximo=-1;
	L->disp=0;
	L->inicio=0;
}
void formar_lista(LISTA_LIGADA_ESTATICA* L){
	int i=L->inicio;
	while(i!=-1){
		L->A[i].reg.l=  rand() % 1000;
		i=L->A[i].proximo;
	}
}
void formatar_lista(LISTA_LIGADA_ESTATICA* L, LISTA_LIGADA_ESTATICA* C) {
    int i;
    for (i = 0; i < N - 1; i++) {
        C->A[i].reg.l = L->A[N - i - 2].reg.l;
    }
}
void exibir_lista(LISTA_LIGADA_ESTATICA* L){
	int i=L->inicio;
	printf("ELEMENTOS:\n");
	while(i!=-1){
		printf("%d\n",L->A[i].reg.l);
		i=L->A[i].proximo;
	}
	printf("\n------------------------------------------------------------\n");
}
