#ifndef LLE_H
#define LLE_H

#define MAX 7
typedef struct{
	int cod;
	int idade;
}reg;
typedef struct{
	reg funcionario;
	int prox;
}ELEMENTO;
typedef struct{
	int disp;
	int inicio;
	ELEMENTO A[MAX];
}Lista;

void criar_lista(Lista* l);

#endif
