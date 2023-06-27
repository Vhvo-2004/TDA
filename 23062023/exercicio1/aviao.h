#ifndef AVIAO_H
#define AVIAO_H

typedef struct{
	char nome[90];
	int identificador;
}Aviao;

typedef struct aux{
	Aviao A;
	struct aux* proximo;
}elemento;

typedef struct{
	elemento* inicio;
	elemento* fim;
}Fila;
void inicializar(Fila* P);
void reinicializar(Fila* P);
int inseriraviao(Fila *P, Aviao R);
void exibir(Fila* P);
int excluir(Fila *P);
int Decolagem(Fila* P);
int contar(Fila* P);
void Listar(Fila* P);


#endif
