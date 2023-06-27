#include<stdio.h>
#include "aviao2.h"
#include<stdlib.h>

void inicializapilha(PILHA* p){
	p->topo=NULL;
}
int inseriraviao(PILHA* p,aviao y){
	elemento* novoNo=(elemento*) malloc(sizeof(elemento));
	novoNo->A=y;
	novoNo->prox=p->topo;
	p->topo=novoNo;
	return 1;
}
int excluiraviao(PILHA* p){
	if(p->topo==NULL){
	  return 0;
}
	elemento* i=p->topo;
	p->topo=p->topo->prox;
	free(i);	
	return 1;
}
int tamanho(PILHA* p){
	elemento* i=p->topo;
	int cont=0;
	while(i!=NULL){
		cont++;
		i=i->prox;
	}
	return cont;
}
int tirar(PILHA* p){
	if(p->topo==NULL){
		return 0;
	}
	elemento* i=p->topo;
	p->topo=p->topo->prox;
	free(i);
	return 1;
}
void imprimepilha(PILHA* P){
	elemento* i=P->topo;
	while(i!=NULL){
		printf("\n Codigo:%d\nNome:%s\n",i->A.cod,i->A.nome);
		i=i->prox;
	}
}
void Listar(PILHA* P){
	printf("\n------------------------------------------\n");
	printf("\nElemento no topo da lista:\n");
	printf("\n Codigo:%d\nNome:%s\n",P->topo->A.cod,P->topo->A.nome);
	printf("\n------------------------------------------\n");
}
void tirar2(PILHA* P, PILHA* T,int pos){
	elemento* i=P->topo;
	int cont=0,aux1=0;
	while(cont!=pos && i!=NULL){
	cont++;
	inseriraviao(T,i->A);
	i=i->prox;
	tirar(P);	
	}
	
		tirar(T);
		elemento* j=T->topo;
		while(j!=NULL){
			inseriraviao(P,j->A);
			j=j->prox;
			tirar(T);
		}	

}
