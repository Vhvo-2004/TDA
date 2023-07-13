#include <stdio.h>
#include <stdlib.h>
#include "hashou.h.h"
#include <string.h>
int main() {
    TB_HASH tabela,tab;
    inicializahash(tabela,9);
    inicializahash(tab,11);
	int chaves[]={12, 44, 13, 88, 23, 94, 11, 39, 20, 16 ,5};
  //Supondo M=9
  printf("Supondo M igual a 9:\n");
  int i;
  for(i=0;i<11;i++){
  	inserir(tabela,chaves[i],m_hash1);
  }
  mostrarhash(tabela,9);
  //Supondo M=11
  printf("Supondo M igual a 11:\n");
  for(i=0;i<11;i++){
  	
  	inserir(tab,chaves[i],m_hash2);
  }
  mostrarhash(tab,11);
  

    return 0;
}

