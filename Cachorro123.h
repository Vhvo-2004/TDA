#ifndef Cachorro123
#define Cachorro123
typedef struct{
	int *aluno;
	int qtd;
}aluno;
aluno* Criar_Aluno();
void Apagar_Aluno(aluno* P);
int QTD_valido(aluno* P);

#endif
