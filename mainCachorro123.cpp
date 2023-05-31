#include<stdio.h>
#include<stdlib.h>
#include "Cachorro123.h"
 int main(){
 	aluno *T;
 	T=Criar_Aluno();
 	
 	printf("A quantidade de alunos validos:%d\n",QTD_valido(T));
 	
 	
 	return 0;
 }
