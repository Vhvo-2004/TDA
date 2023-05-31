#include<stdio.h>
#include<stdlib.h>
#include "Cachorro123.h"
#include<math.h>
aluno* Criar_Aluno(){
	int i;
aluno* P= (aluno*) malloc(sizeof(aluno));
P->aluno=(int*) malloc(100*sizeof(int));
int qtd=rand() % 100;
for(i=0;i<qtd;i++){
		*(P->aluno + i)= rand() % 100;
	}
	for(int j=0;j<qtd;j++){
		printf("O numero do aluno %d: %d \n",qtd,*(P->aluno + j));
	}
return P;
}
void Apagar_Aluno(aluno* P){
	if(P->aluno==NULL){
		free(P->aluno);
	}else{
		if(P==NULL){
			return;
		}
		free(P);
	}
}
int QTD_valido(aluno* P){
	int i,j=0;
	for(i=0;i<P->qtd;i++){
		if(P->aluno[i] != NULL){
			j++;
		}else{
			return j;
		}
	}
	
	
	
}

