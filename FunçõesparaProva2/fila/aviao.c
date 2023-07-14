#include<stdio.h>
#include "aviao.h"
#include <stdlib.h>
void inicializar(Fila* P){
	P->fim=NULL;
	P->inicio=NULL;
}
void reinicializar(Fila* P){
	elemento* apagar;
	elemento* elem=P->inicio;
	while(elem!= NULL){
		apagar=elem;
		elem=elem->proximo;
		free(apagar);
		
	}
	P->inicio=NULL;
}
void exibir(Fila* P){
	elemento* elem=P->inicio;
	printf("Lista da Fila:\n");
	while(elem!= NULL){
		printf("Numero do aviao:%d\nNome do aviao:%s\n",elem->A.identificador,elem->A.nome);
		elem=elem->proximo;
		}
}
int inseriraviao(Fila *P, Aviao R){
	elemento* i = (elemento*) malloc(sizeof(elemento));
	if(i==NULL){
		return 0;
	}
	i->A=R;
	i->proximo=NULL;
	if(P->inicio==NULL){
		P->inicio=i;
	}else{
		P->fim->proximo=i;
	}
	P->fim=i;
	return 1;
}

int Decolagem(Fila* P){
	if(P->inicio==NULL){
		printf("Fila Vazia!\n");
		return 0;
	}
	elemento* i=P->inicio;
	printf("O aviao de nome %s decolou!\n",i->A.nome);
	P->inicio=P->inicio->proximo;
	free(i);
	return 1;
}
int contar(Fila* P){
	int cont=0;
	elemento* i=P->inicio;
	while(i!=NULL){
		cont++;
		i=i->proximo;
	}
	return cont;
}
void Listar(Fila* P){
	printf("Primeiro da lista:\n");
	printf("\n--------------------------------------------------------\n");
	printf("\nNumero de codigo:%d\nNome:%s\n",P->inicio->A.identificador,P->inicio->A.nome);
	printf("\n--------------------------------------------------------\n");
}
