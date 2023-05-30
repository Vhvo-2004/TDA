#include<stdio.h>
#include<stdlib.h>
#include "turma.h"

TURMA* Criar_Turma(int qtd){
	TURMA *P= (TURMA*) malloc(sizeof(TURMA));
	P->qtd=qtd;
	P->T= (ALUNO*) malloc(qtd*sizeof(ALUNO));
	return P;
}
ALUNO Criar_Aluno(){
	ALUNO a;
	printf("Insira o nome do aluno:\n");
	scanf("%s",a.nome);
	printf("Insira o codigo do aluno:\n");
	scanf("%d",&a.cod);
	printf("Insira a idade do aluno:\n");
	scanf("%d",&a.idade);
	printf("Insira o coeficiente do aluno:\n");
	scanf("%f",&a.cf);
	return a;
}
void printar_alunos(TURMA *P){
	for(int i=0;i<P->qtd;i++){
		printf("Nome: %s\n",P->T[i].nome);
		printf("Codigo: %d\n",P->T[i].cod);
		printf("Idade: %d\n",P->T[i].idade);
		printf("Coeficiente: %f\n",P->T[i].cf);
	}
	printf("\n");
}
void Inserir_alunos(TURMA *P){
	int i;
	printf("Insira os dados do alunos da turma:\n");
	for(i=0;i< P->qtd; i++){
		*(P->T+i)=Criar_Aluno();
	}
}

void Liberar(TURMA *P){
	if(P==NULL){
		return;
	}
	if(P->T != NULL){
		for(int i=0;i<P->qtd;i++){
			free(P->T[i].nome);
		}
		free(P->T);
	}
	free(P);
}
void Busca_Sequencial(TURMA *P,int chave){
	int i;
	for(i=0;i<P->qtd;i++){
		if(chave==P->T[i].cod){
		printf("O aluno procurado eh(Busca Sequencial):\n");	
		printf("Nome: %s\n",P->T[i].nome);
		printf("Codigo: %d\n",P->T[i].cod);
		printf("Idade: %d\n",P->T[i].idade);
		printf("Coeficiente: %f\n",P->T[i].cf);
		return;
		}
	}
	printf("(Busca Sequencial)Nao esta nessa turma!\n");
		return;
}
ALUNO* Busca_BinariaRecursiva(TURMA *P, int chave, int inicio, int fim){
	if( inicio> fim){
		return NULL;
	}
	int meio=(inicio+fim)/2;
	if(P->T[meio].cod==chave){
		return &(P->T[meio]);
	}else if(P->T[meio].cod>chave){
		return Busca_BinariaRecursiva(P,chave,inicio,meio-1);
	}else{
		return Busca_BinariaRecursiva(P,chave,meio+1,fim);
	}
}

