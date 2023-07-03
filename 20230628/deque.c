#include<stdio.h>
#include "deque.h"
#include <string.h>
#include <stdlib.h>
void inicializaDeque(DEQUE* d){
	d->cabeca=(ELEMENTO*) malloc(sizeof(ELEMENTO));
	d->cabeca->anterior=d->cabeca;
	d->cabeca->proximo=d->cabeca;
}
void reinicializar(DEQUE* d){
	ELEMENTO* apagar;
	ELEMENTO* elem=d->cabeca->proximo;
	while(elem != d->cabeca){
		apagar=elem;
		elem=elem->proximo;
		free(apagar);
	}
	d->cabeca->anterior=d->cabeca;
	d->cabeca->proximo=d->cabeca;
}
int inserirelemento(DEQUE* d, char exp[]){
	ELEMENTO* i;
	i=(ELEMENTO*) malloc(sizeof(ELEMENTO));
	strcpy(i->nome,exp);
	i->proximo=d->cabeca;
	i->anterior= d->cabeca->anterior;
	d->cabeca->anterior=i;
	i->anterior->proximo=i;
	return 1;
}
void exibe(int pos,char carac,DEQUE* d){
	ELEMENTO* i=d->cabeca;
	ELEMENTO* j=d->cabeca;
	int u=0,w=0;
	while(u!=pos){
		i=i->proximo;
		u++;
	}
	if(carac=='i'){
		while(i!=d->cabeca || w == 0){
		printf("%s\n",i->nome);		
		i=i->anterior;
		w++;
	}
	}
	if(carac=='d'){
		while(i!=d->cabeca || w == 0){
		printf("%s\n",i->nome);		
		i=i->proximo;
		w++;
	}
	}
	if(carac!='d' && carac!='i'){
		printf("caractere invalido!\n");
		return;
	}
}



