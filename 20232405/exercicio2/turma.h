#ifndef TURMA_H
#define TURMA_H
typedef struct{
	int cod;
	char nome[90];
	int idade;
	float cf;
}ALUNO;
typedef struct{
	ALUNO *T;
	int qtd;
}TURMA;
TURMA* Criar_Turma(int qtd);
ALUNO Criar_Aluno();
void Inserir_alunos(TURMA *P);
void Liberar(TURMA *P);
void printar_alunos(TURMA *P);
void Busca_Sequencial(TURMA *P,int chave);
ALUNO* Busca_BinariaRecursiva(TURMA *P, int chave, int inicio, int fim);

#endif
