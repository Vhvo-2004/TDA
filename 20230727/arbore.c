#include<stdio.h>
#include "arbore.h"
#include <stdlib.h>
void inicializar(ARVORE* a){
	a->raiz=NULL;
}

NO* criarno(PACIENTE p){
	NO* novoNo= (NO*) malloc(sizeof(NO));
	novoNo->pac=p;
	novoNo->esquerda=NULL;
	novoNo->direita=NULL;
	return (novoNo);
}
bool adiciona(ARVORE* a,NO* novo){
	a->raiz= inserir(a->raiz,novo);
	return true;
}
NO* inserir(NO* raiz,NO* no){
	if(raiz==NULL){
	 return (no);
	 }
	 if(raiz->pac.cod > no->pac.cod ){
	 	raiz->esquerda=inserir(raiz->esquerda, no);
	 }else{
	 	raiz->direita= inserir(raiz->direita,no);
	 }
	return (raiz);
}
bool adiciona2(ARVORE* a,PACIENTE p){
	NO* novoNo= (NO*) malloc(sizeof(NO));
	novoNo->pac=p;
	novoNo->direita=NULL;
	novoNo->esquerda=NULL;
	adiciona(a,novoNo);
		return true;
}
void listarNOS(NO* raiz){
	
	if(raiz!=NULL){
		printf("\n---------------------------------------------------\n");
		printf("Endereco:%p\n ", raiz);
		printf("Na esquerda: %p\n", raiz->esquerda);
		printf("Na direita: %p\n", raiz->direita);
		printf("Codigo: %d\n", raiz->pac.cod);
		listarNOS(raiz->esquerda);
		listarNOS(raiz->direita);
	}
}
void listarArvore(ARVORE* a){
	listarNOS(a->raiz);
}
NO* contem(NO* raiz, int cod){
	if(raiz==NULL){
		return NULL;
	}
	if(raiz->pac.cod==cod){
		return raiz;
	}
	if(raiz->pac.cod>cod){
		return(contem(raiz->esquerda,cod));
	}else{
		return(contem(raiz->direita,cod));
	}
	
}
NO* buscar(ARVORE* a, int cod){
	return (contem(a->raiz,cod));
}
void contagem(NO* a,int* cont){
	int j;
	if(a!=NULL){
		*cont=*cont+1;
		contagem(a->direita,cont);
		contagem(a->esquerda,cont);
	}
}
int quantidade(ARVORE* a){
	int b;
	contagem(a->raiz,&b);
	printf("Quantidade:%d\n",b);
	return 0;
}
void P_O1(NO* a){
	if(a!=NULL){
		printf("%d\n",a->pac.cod);
		P_O1(a->esquerda);
		P_O1(a->direita);
	}
}
void P_O(ARVORE* a){
	P_O1(a->raiz);
}
void I_O1(NO* a){
	if(a!=NULL){
		I_O1(a->esquerda);
		printf("%d\n",a->pac.cod);
		I_O1(a->direita);
	}
}
void I_O(ARVORE* a){
	I_O1(a->raiz);
}
void P_P1(NO* a){
	if(a!=NULL){
		P_P1(a->esquerda);
		P_P1(a->direita);
		printf("%d\n",a->pac.cod);
	}
}
void P_P(ARVORE* a){
	P_P1(a->raiz);
}
