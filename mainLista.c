#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
	Lista *a;
	int i=0,d=0;
	printf("Quantos termos nessa lista:\n");
	scanf("%d",&i);
	a=Criar_Lista(i);
	for(d=0;d< a->n ;d++){
		scanf("%d",a->V+d);
	}
	for(d=0;d< a->n ;d++){
		printf("%d\n",*(a->V+d));
	}
	Limpar_Lista(a);
	
}


