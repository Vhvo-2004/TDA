#include<stdio.h>
#include "deque.h"
#include <string.h>
#include <stdlib.h>



int main(){
	DEQUE A;
	inicializaDeque(&A);
	inserirelemento(&A,"RAFAEL SOUZA");
	inserirelemento(&A,"BRUNA SILVA");
	inserirelemento(&A,"MARCOS SANTOS");
	inserirelemento(&A,"CLOVIS PEREIRA");
	inserirelemento(&A,"TANIA OLIVEIRA");
	printf("Lista Completa:\n");
	exibe(4,'d',&A);
	printf("Lista Cortada:\n");
	exibe(2,'i',&A);
	printf("Lista Cortada:\n");
	exibe(1,'d',&A);
	return 0;
}
