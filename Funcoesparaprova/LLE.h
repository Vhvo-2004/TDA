#ifndef LLE_H
#define LLE_H

#define MAX 20
typedef struct{
	int matricula;
}reg;
typedef struct{
	int prox;
	int valor;
}ELEMENTO;
typedef struct{
	ELEMENTO A[MAX];
	int disp;
	int inicio;
}Lista;

void criar_lista(Lista* l);
int oberdisponivel(Lista* l);
void inserirelemento(Lista* l,int valor);
void exibir(Lista* m);

#endif
