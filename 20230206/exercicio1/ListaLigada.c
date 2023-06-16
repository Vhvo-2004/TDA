#include<stdio.h>
#include<stdlib.h>
#include "ListaLigada.h"
#include<string.h>
void inicializarLista(LISTA* l) {
    int i;
    for(i = 0; i < MAX - 1; i++){
        l->A[i].prox = i + 1;
    }
    l->A[MAX - 1].prox = -1;
    l->inicio = -1;
    l->dispo = 0;
}

int tamanho(LISTA* l) {
    int i = l->inicio;
    int tam = 0;
    while(i != INVALIDO) {
        tam++;
        i = l->A[i].prox;
    }
    return tam;
}

void LerLista(LISTA* l) {
    int i = l->inicio;
    int t = 0;
    while(i != INVALIDO || t == 0) {
        t = 1;
        printf("O elemento %d da lista:\n", i);
        printf("O nome:\n");
        scanf("%s", l->A[i].reg.nome);
        printf("A idade:\n");
        scanf("%d", &l->A[i].reg.idade);
        printf("A matricula:\n");
        scanf("%d", &l->A[i].reg.matricula);
        i = l->A[i].prox;
    }
}

void ExibirLista(LISTA* l) {
    int i = l->inicio;
    while(i != INVALIDO) {
        printf("O nome %s\nA idade: %d\nA matricula: %d\n", l->A[i].reg.nome, l->A[i].reg.idade, l->A[i].reg.matricula);
        i = l->A[i].prox;
        printf("\n----------------------------------------\n");
    }
}

void lista_cheia(LISTA* l) {
    if(MAX == tamanho(l)) {
    	printf("\n----------------------------------------\n");
        printf("Esta cheio!\n");
        printf("\n----------------------------------------\n");
    } else {
    	printf("\n----------------------------------------\n");
        printf("Nao esta cheio.\n");
        printf("\n----------------------------------------\n");
    }
}
int obterNo(LISTA* l){
	int disp=l->dispo;
	if(l->dispo!=-1){
		l->dispo=l->A[disp].prox;
	}
	return disp;
}
bool inserirElemento(LISTA* l, REGISTRO novo_aluno){
	if(l->dispo==-1){
		return false;
	}
	int i=l->inicio;
	int pos_inserir=-1;
	while((i!= -1) && (novo_aluno.matricula>l->A[i].reg.matricula)){
		pos_inserir=i;
		i=l->A[i].prox;
	}
	if((i!=-1) && (novo_aluno.matricula)== l->A[pos_inserir].reg.matricula){
		return false;
	}
	i=obterNo(l);
	l->A[i].reg=novo_aluno;
	if(pos_inserir==-1){
		l->A[i].prox=l->inicio;
		l->inicio=i;
	}else{
		l->A[i].prox=l->A[pos_inserir].prox;
		l->A[pos_inserir].prox=i;
	}
	
}
bool excluirAluno(LISTA* l, int matricula){
	int i=l->inicio;
	int anterior=-1;
	while(i!= -1 && l->A[i].reg.matricula<matricula){
		anterior=i;
		i=l->A[i].prox;
	}
	if(i != -1 && l->A[i].reg.matricula != matricula){
		return false;
	}
	if(anterior==-1){
		l->inicio=l->A[i].prox;
	}else{
		l->A[anterior].prox=l->A[i].prox;
		alocarNo(l,i);
		return true;
	}
	
}
void alocarNo(LISTA* l, int i){
	l->A[i].prox=l->dispo;
	l->dispo=i;
}

REGISTRO criarAluno(int matricula, const char* nome, int idade) {
    REGISTRO aluno;
    aluno.matricula = matricula;
    strcpy(aluno.nome, nome);
    aluno.idade = idade;
    return aluno;
}
void alterarMatricula(LISTA* l, TIPOCHAVE matricula, TIPOCHAVE novaMatricula) {
    bool alunoExcluido = excluirAluno(l, matricula);
    if (alunoExcluido) {
        REGISTRO novoAluno;
        novoAluno.matricula = novaMatricula;
        inserirElemento(l, novoAluno);
    }
}
		
	


