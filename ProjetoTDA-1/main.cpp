#include<stdio.h>
#include<stdlib.h>
#include"ComplexeCubo.h"

int main(){
	Cubo *A;
	float lado=3;
	A=Criar_Cubo(lado);
	printf("O Lado do cubo eh: %f\n",A->lado);
	printf("A Area do cubo eh: %f\n",A->Area);
	printf("O Volume do cubo eh: %f\n",A->Volume);
	Complexo *B1,*B2,*Soma,*Sub,*Mul,*Div;
	B1=Criar_complexo(1,1);
	B2=Criar_complexo(1,2);
	Soma=Soma_Complexo(B1,B2);
	Sub=Sub_Complexo(B1,B2);
	Mul=Mul_Complexo(B1,B2);
	Div=Div_Complexo(B1,B2);
	printf("A soma entre complexos deu igual a: \n%.1f %.1fi\n",Soma->Real,Soma->imaginario);
	printf("A diferenca entre complexos deu igual a: \n%.1f %.1fi\n",Sub->Real,Sub->imaginario);
	printf("O produto entre complexos deu igual a: \n%.1f %.1fi\n",Mul->Real,Mul->imaginario);
	printf("A Razao entre complexos deu igual a: \n%.1f %.1fi\n",Div->Real,Div->imaginario);
	Apaga_Complexo(B1);
	Apaga_Complexo(B2);
	Apaga_Complexo(Soma);
	Apaga_Complexo(Sub);
	Apaga_Complexo(Mul);
	Apaga_Complexo(Div);
	Apaga_Cubo(A);
	return  0;
}
