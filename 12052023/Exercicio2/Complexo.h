#ifndef COMPLEXO_H
#define COMPLEXO_H
typedef struct{
	float Real;
	float imaginario;
}Complexo;

Complexo* Criar_complexo(float R, float i);
void Apaga_Complexo(Complexo *P);
Complexo* Soma_Complexo(Complexo *A1,Complexo *A2);
Complexo* Sub_Complexo(Complexo *A1,Complexo *A2);
Complexo* Mul_Complexo(Complexo *A1,Complexo *A2);
Complexo* Div_Complexo(Complexo *A1,Complexo *A2);
#endif /* COMPLEXO_H */
