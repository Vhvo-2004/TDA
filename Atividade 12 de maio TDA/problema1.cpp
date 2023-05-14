#include<stdio.h>
#include<stdlib.h>
typedef struct{
	float lado;
	float Area;
	float Volume;
}Cubo;
Cubo* Criar_Cubo(float lado){
	Cubo *C= (Cubo*) malloc(sizeof(Cubo));
	C->lado=lado;
	C->Area=lado*lado*6;
	C->Volume=lado*lado*lado;
	return C;
}

int main(){
	Cubo *A;
	float lado=3;
	A=Criar_Cubo(lado);
	printf("O Lado do cubo eh: %f\n",A->lado);
	printf("A Area do cubo eh: %f\n",A->Area);
	printf("O Volume do cubo eh: %f\n",A->Volume);
	
	return  0;
}
