#include<stdio.h>
#include<stdlib.h>
#include "turma.h"

int main(){
	TURMA *P;
	ALUNO *P1;
	int chave=1;
	P=Criar_Turma(3);
	Inserir_alunos(P);
	Busca_Sequencial(P,chave);
	P1=Busca_BinariaRecursiva(P,chave,0,P->qtd-1);
	if(P1!=NULL){
	printf("O aluno procurado eh(Busca Sequencial Binaria):\n");	
	printf("Nome: %s\n",P1->nome);
	printf("Codigo: %d\n",P1->cod);
	printf("Idade: %d\n",P1->idade);
	printf("Coeficiente: %f\n",P1->cf);
	printf("\n");
	}else{
		printf("O aluno nao foi encontrado(Busca Sequencial Binaria)\n");
	}
	printf("\n As informacoes de todos os alunos:\n");
	printar_alunos(P);
	Liberar(P);
	return 0;
}
