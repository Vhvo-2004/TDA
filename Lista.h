#ifndef Lista_H
#define Lista_H
typedef struct{
	int n;
	int *V;
}Lista;

Lista* Criar_Lista(int i);
void Limpar_Lista(Lista* P);
#endif
