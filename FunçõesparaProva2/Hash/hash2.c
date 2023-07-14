#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash2.h"

int m_hash(int cod) {
    return (cod % N);
}

void inicializahash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}

void inserir(TB_HASH tab, PACIENTE pac) {
    int h = m_hash(pac.cod);
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return;
    }
    newNode->pac = pac;
    newNode->next = NULL;
    
    if (tab[h] == NULL) {
        tab[h] = newNode;
    } else {
        NODE* current = tab[h];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void excluir(TB_HASH tab, int cod){
	int h= m_hash(cod);
	NODE* current = tab[h];
	NODE* before=NULL;
    while (current != NULL) {
        if (current->pac.cod == cod){
            if(before==NULL){
            	tab[h]=current->next;
            	free(current);
            	return;
            	
			}else{
				before->next=current->next;
				free(current);
				return;
			}
        }
        before=current;
        current = current->next;
    }
    printf("Nao encontrado elemento que deseja excluir!\n");
    return;
	
	
}


void mostrarhash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            NODE* current = tab[i];
            printf("\nPacientes nessa lista no endereco %d:\n", i);
            while (current != NULL) {
                printf("Codigo do Paciente: %d\n", current->pac.cod);
                printf("Nome: %s\n", current->pac.nome);
                printf("CPF: %s\n", current->pac.cpf);
                printf("Idade: %d\n", current->pac.idade);
                current = current->next;
            }
        } else {
            printf("Paciente: %d NULL\n", i);
        }
    }
}

PACIENTE* busca(TB_HASH tab, int cod) {
    int h = m_hash(cod);
    NODE* current = tab[h];
    while (current != NULL) {
        if (current->pac.cod == cod) {
            return &(current->pac);
        }
        current = current->next;
    }
    return NULL;
}

