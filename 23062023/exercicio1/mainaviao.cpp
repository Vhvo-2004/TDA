#include<stdio.h>
#include "aviao.h"

int main(){
	Fila Q;
	int v,b,n;
	Aviao A={"LATAM",1239184};
	Aviao B={"GOL",768345};
	Aviao C={"Azul",975249};
	Aviao D={"EMIRATES",942346};
	inicializar(&Q);
	exibir(&Q);
	inseriraviao(&Q,A);
	exibir(&Q);
	inseriraviao(&Q,B);
	exibir(&Q);
	inseriraviao(&Q,C);
	exibir(&Q);
	Listar(&Q);
	Decolagem(&Q);
	exibir(&Q);
	Listar(&Q);
	inseriraviao(&Q,D);
	exibir(&Q);
	Decolagem(&Q);
	exibir(&Q);
	Decolagem(&Q);
	exibir(&Q);
	return 0;
}
