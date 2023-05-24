#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"


Lista* Criar_Lista(int i){
	Lista* a= (Lista*) malloc(sizeof(Lista));
	a->n=i;
	a->V=(int*) malloc(i*sizeof(int));
	return a;
}
void Limpar_Lista(Lista* P){
	free(P);
}


