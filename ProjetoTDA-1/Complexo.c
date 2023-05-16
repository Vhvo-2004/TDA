#include<stdio.h>
#include<stdlib.h>
#include "ComplexeCubo.h"
Complexo* Criar_complexo(float R, float i){
	Complexo *A=(Complexo*) malloc(sizeof(Complexo));
	(*A).Real=R;
	(*A).imaginario=i;
	return A;
}

void Apaga_Complexo(Complexo *P){
	free(P);
}
Complexo* Soma_Complexo(Complexo *A1,Complexo *A2){
	Complexo *Soma=(Complexo*) malloc(sizeof(Complexo));
	(*Soma).Real=(*A1).Real+(*A2).Real;
	(*Soma).imaginario=(*A1).imaginario+(*A2).imaginario;
	return Soma;
}
Complexo* Sub_Complexo(Complexo *A1,Complexo *A2){
	Complexo *Sub=(Complexo*) malloc(sizeof(Complexo));
	(*Sub).Real=(*A1).Real-(*A2).Real;
	(*Sub).imaginario=(*A1).imaginario-(*A2).imaginario;
	return Sub;
}
Complexo* Mul_Complexo(Complexo *A1,Complexo *A2){
	Complexo *Mul=(Complexo*) malloc(sizeof(Complexo));
	(*Mul).Real=(*A1).Real * (*A2).Real - (*A1).imaginario * (*A2).imaginario;
	(*Mul).imaginario=(*A1).Real * (*A2).imaginario + (*A1).imaginario * (*A2).Real;
	return Mul;
}
Complexo* Div_Complexo(Complexo *A1,Complexo *A2){
	int l;
	Complexo *Div=(Complexo*) malloc(sizeof(Complexo));
	Complexo *aux = (Complexo*) malloc(sizeof(Complexo));
	Complexo *auxD = (Complexo*) malloc(sizeof(Complexo));
	Complexo *auxN = (Complexo*) malloc(sizeof(Complexo));
	if(A2->imaginario==0 && A2->Real==0){
		printf("Impossivel dividir por 0!\n");
		l=1;
	}
	if(A2->imaginario==0 && l==0){
		Div->imaginario=A1->imaginario/A2->Real;
		Div->Real=A1->Real/A2->Real;
	}else{
		*aux=*A2;
		aux->imaginario=-(*A2).imaginario;
		auxD=Mul_Complexo(A2,aux);
		auxN=Mul_Complexo(A1,aux);
		(*Div).Real=(*auxN).Real/auxD->Real;
		(*Div).imaginario=(*auxN).imaginario/(*auxD).Real;
		free(aux);
		free(auxD);
		free(auxN);
	}
	return Div;
}

