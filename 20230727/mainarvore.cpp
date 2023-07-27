#include <stdio.h>
#include "arbore.h"
int main(){
	ARVORE a;
	inicializar(&a);
	PACIENTE np;
	int i=0;
	np.cod=24;
	NO* novo=criarno(np);
	adiciona2(&a,np);
	np.cod=10;
	adiciona2(&a,np);
	np.cod=32;
	adiciona2(&a,np);
	np.cod=5;
	adiciona2(&a,np);
	np.cod=12;
	adiciona2(&a,np);
	np.cod=29;
	adiciona2(&a,np);
	np.cod=35;
	adiciona2(&a,np);
	printf("\n-----------------------------Teste de Listagem-------------------------------------\n");
	listarArvore(&a);
	printf("\n-----------------------------Teste de Busca-------------------------------------\n");
	while(i<=35){
	
	if(buscar(&a,i)!=NULL){
	printf("%d foi encontrado na busca!\n",buscar(&a,i)->pac.cod);
}else{
	printf("NULL\n");
}
i++;
}
quantidade(&a);
printf("\n-----------------------------Teste de Listagem(PRE-ORDEM)-------------------------------------\n");
P_O(&a);
printf("\n-----------------------------Teste de Listagem(IN-ORDEM)-------------------------------------\n");
I_O(&a);
printf("\n-----------------------------Teste de Listagem(POS-ORDEM)-------------------------------------\n");
P_P(&a);
	return 0;
}
