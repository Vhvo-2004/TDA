#include<stdio.h>
#include "LLE.h"
int main(){
	Lista a;
	criar_lista(&a);
	inserirelemento(&a,1);
	inserirelemento(&a,1);
	inserirelemento(&a,1);
	inserirelemento(&a,1);
	inserirelemento(&a,1);
	inserirelemento(&a,2);
	exibir(&a);
	return 0;
}
