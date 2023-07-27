#ifndef ARBORE_H
#define ARBORE_H
typedef struct{
	int cod;
}PACIENTE;
typedef struct aux{
	PACIENTE pac;
	aux* esquerda;
	aux* direita;
}NO;
typedef struct{
	NO* raiz;
}ARVORE;

void inicializar(ARVORE* a);
NO* criarno(PACIENTE P);
NO* inserir(NO* raiz,NO* no);
bool adiciona(ARVORE* a,NO* novo);
bool adiciona2(ARVORE* a,PACIENTE p);
void listarNOS(NO* raiz);
void listarArvore(ARVORE* a);
NO* contem(NO* a, int cod);
NO* buscar(ARVORE* a, int cod);
void contagem(NO* a);
int quantidade(ARVORE* a);
void P_O1(NO* a);
void P_O(ARVORE* a);
void I_O1(NO* a);
void I_O(ARVORE* a);
void P_P1(NO* a);
void P_P(ARVORE* a);
#endif
