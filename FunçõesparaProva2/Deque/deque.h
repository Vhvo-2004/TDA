#ifndef DEQUE_H
#define DEQUE_H
typedef struct aux{
	char nome[50];
	struct aux* anterior;
	struct aux* proximo;
}ELEMENTO;
typedef struct{
	ELEMENTO* cabeca;
}DEQUE;
void inicializaDeque(DEQUE* d);
void reinicializar(DEQUE* d);
void exibe(int pos,char carac,DEQUE* d);
int inserirelemento(DEQUE* d, char exp[]);

#endif
