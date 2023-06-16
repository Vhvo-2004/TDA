#include<stdio.h>
#include "LLE.h"
#define MAX 20
void criar_lista(Lista* l){
	int i;
	for(i=0;i<MAX-1;i++){
		l->A[i].prox=i+1;
	}
	l->A[MAX-1].prox=-1;
	l->disp=0;
	l->inicio=-1;
	
}

int obterdisponivel(Lista* m){
	int disp=m->disp;
	if(m->disp != -1){
		m->disp=m->A[disp].prox;
	}
	return disp;
}
void exibir(Lista* m){
	int i=m->inicio;
	while(i!=-1){
		printf("%d \n",m->A[i].valor);
		i=m->A[i].prox;
	}
}
void inserirelemento(Lista* m, int valor){
	if(m->disp==-1){
		return;
	}
	int i=m->inicio;
	int pos_inserir=-1;
	while(i!=-1){
		pos_inserir=i;
		i=m->A[i].prox;
	}
	i=obterdisponivel(m);
	m->A[i].valor=valor;
	if(pos_inserir==-1){
		m->A[i].prox=m->inicio;
		m->inicio=i;
	}else{
		m->A[i].prox=m->A[pos_inserir].prox;
		m->A[pos_inserir].prox=i;
	}
}

