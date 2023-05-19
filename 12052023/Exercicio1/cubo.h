#ifndef CUBO_H
#define CUBO_H
typedef struct{
	float lado;
	float Area;
	float Volume;
}Cubo;
Cubo* Criar_Cubo(float lado);
void Apaga_Cubo(Cubo *T);
#endif 
