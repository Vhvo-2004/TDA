#include<stdio.h>
#include<stdlib.h>
#include "ComplexeCubo.h"
Cubo* Criar_Cubo(float lado){
	Cubo *C= (Cubo*) malloc(sizeof(Cubo));
	C->lado=lado;
	C->Area=lado*lado*6;
	C->Volume=lado*lado*lado;
	return C;
}
void Apaga_Cubo(Cubo *A){
	free(A);
}
