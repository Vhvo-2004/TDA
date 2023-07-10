#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
int m_hash(int cod) {
    return (cod % N);
}

int inserir(TB_HASH tab, PACIENTE pac) {
    int h = m_hash(pac.cod);
    while (tab[h] != NULL) {
        if (tab[h]->cod == pac.cod && tab[h]->disp==0) {
        	printf("Ja existe paciente com esse codigo!\n");
            return 0;
        }
        if(tab[h]->disp==1){
    tab[h]->cod = pac.cod;
    tab[h]->nome = strdup(pac.nome);
    tab[h]->cpf = strdup(pac.cpf);
    tab[h]->idade = pac.idade;
    tab[h]->disp=0;	
    return 1;
		}
        h = (h + 1) % N;
    }
    
    tab[h] = (PACIENTE*) malloc(sizeof(PACIENTE));
    if (tab[h] == NULL || tab[h]->disp == 0){
    	printf("Ja tem um paciente nessa posicao!\n");
        return 0;
    }
	
    tab[h]->cod = pac.cod;
    tab[h]->nome = strdup(pac.nome);
    tab[h]->cpf = strdup(pac.cpf);
    tab[h]->idade = pac.idade;
    tab[h]->disp=0;

    return 1;
}
void excluir_paciente(TB_HASH tab,int cod){
	int h=m_hash(cod);
	while(tab[h]!= NULL){
		if(tab[h]->cod==cod){
			tab[h]->disp=1;
			return;
		}
		h= (h+1) % N;
	}
	
}

void inicializahash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}

PACIENTE* busca(TB_HASH tab, int cod) {
    int h = m_hash(cod);
    while (tab[h] != NULL) {
        if (tab[h]->cod == cod && tab[h]->disp==0) {
            return tab[h];
        }
        h = (h + 1) % N;
    }
    printf("\nEsse paciente de codigo %d nao existe!\n",cod);
    return NULL;
}

void mostrarhash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            printf("\nPaciente: %d\n", i);
            printf("Codigo do Paciente: %d\n", tab[i]->cod);
            printf("Nome: %s\n", tab[i]->nome);
            printf("CPF: %s\n", tab[i]->cpf);
            printf("Idade: %d\n", tab[i]->idade);
            printf("Disp: %d\n", tab[i]->disp);
        } else {
            printf("Paciente: %d NULL\n", i);
        }
    }
}
