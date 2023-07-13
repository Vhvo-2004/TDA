#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashou.h.h"

int m_hash1(int cod) {
    return ((2*cod + 5) % N);
}
int m_hash2(int cod) {
    return ((2*cod + 5) % M);
}

void inicializahash(TB_HASH tab,int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        tab[i] = NULL;
    }
}

void inserir(TB_HASH tab, int pac, int (*func1)(int)) {
    int h = func1(pac);
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return;
    }
    
    newNode->pac = pac;
    newNode->next = NULL;
    
    if (tab[h] == NULL){
        tab[h] = newNode;
    } else {
        NODE* current = tab[h];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void mostrarhash(TB_HASH tab,int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (tab[i] != NULL) {
            NODE* current = tab[i];
            printf("\nChaves nessa lista no endereco %d:\n", i);
            while (current != NULL) {
                printf("%d ", current->pac);
                current = current->next;
            }
          printf("NUll\n");  
        }else{
        printf("\nChaves nessa lista no endereco %d:\n", i);
        printf("NUll\n");
    }
    }
}



