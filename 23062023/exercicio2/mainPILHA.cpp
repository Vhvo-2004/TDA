#include<stdio.h>
#include "aviao2.h"
int main(){
	PILHA A,aux;
	aviao T={1,"ABUBAKAR"};
	aviao L={2,"AZUL"};
	aviao G={3,"DUENDE"};
	aviao P={4,"Carapana"};
	inicializapilha(&aux);
	inicializapilha(&A);
	inseriraviao(&A,T);
	inseriraviao(&A,L);
	inseriraviao(&A,G);
	inseriraviao(&A,P);
	
	Listar(&A);
	imprimepilha(&A);
	printf("Tirar de posicao teste\n");
	printf("\n-----------------------------------------------------------\n");
	tirar2(&A,&aux,3);
	printf("\n-----------------------------------------------------------\n");
	imprimepilha(&A);
	return 0;
}
