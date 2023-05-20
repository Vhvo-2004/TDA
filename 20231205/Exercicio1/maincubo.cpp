#include<stdio.h>
#include<stdlib.h>
#include "cubo.h"

int main(){
	Cubo *A;
	float lado=3;
	A=Criar_Cubo(lado);
	printf("O Lado do cubo eh: %f\n",A->lado);
	printf("A Area do cubo eh: %f\n",A->Area);
	printf("O Volume do cubo eh: %f\n",A->Volume);
	Apaga_Cubo(A);
	return  0;
}
