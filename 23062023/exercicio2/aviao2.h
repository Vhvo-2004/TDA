#ifndef AVIAO2_H
#define AVIAO2_H
typedef struct{
	int cod;
	char nome[50];
}aviao;

typedef struct aux{
	aviao A;
	struct aux* prox;
}elemento;

typedef struct{
	elemento* topo;
}PILHA;
void inicializapilha(PILHA* p);
int inseriraviao(PILHA* p,aviao y);
int excluiraviao(PILHA* p);
void imprimepilha(PILHA* P);
int tamanho(PILHA* P);
int tirar(PILHA* P);
void Listar(PILHA* P);
void tirar2(PILHA* P, PILHA* aux,int pos);

#endif

