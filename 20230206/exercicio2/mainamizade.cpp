#include<stdio.h>
#include "lista.h"

int main(){
	LISTA_LIGADA_ESTATICA a,c;
	inicializarLista(&a);
	inicializarLista(&c);
	formar_lista(&a);
	formatar_lista(&a,&c);
	printf("Lista a):\n");
	exibir_lista(&a);
	printf("\n-------------------------------------------------\n");
	printf("Lista b):\n");
	exibir_lista(&c);
	printf("\n-------------------------------------------------\n");
	
	return 0;
}
