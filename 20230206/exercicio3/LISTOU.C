#include<stdio.h>
#include "lista.h"
#include<math.h>
#include<stdlib.h>

void inicializarLista(LISTA_LIGADA_ESTATICA* L){
    int i;
    for(i = 0; i < N - 1; i++){
        L->A[i].proximo = i + 1;
    }
    L->A[N - 1].proximo = -1;
    L->disp = 0;
    L->inicio = 0;
}

void formar_lista(LISTA_LIGADA_ESTATICA* L){
    int i = L->inicio;
    while(i != -1){
        L->A[i].reg.l = rand() % 1000;
        i = L->A[i].proximo;
    }
}

void exibir_lista(LISTA_LIGADA_ESTATICA* L){
    int i = L->inicio;
    printf("ELEMENTOS:\n");
    while(i != -1){
        printf("%d\n", L->A[i].reg.l);
        i = L->A[i].proximo;
    }
    printf("\n------------------------------------------------------------\n");
}

void copiar_lista(LISTA_LIGADA_ESTATICA* L1, LISTA_LIGADA_ESTATICA* L2){
    int i = L1->inicio;
    int j = 0;
    while(i != -1){
        L2->A[j].reg.l = L1->A[i].reg.l;
        j++;
        i = L1->A[i].proximo;
    }
}

void concatenar_listas(LISTA_LIGADA_ESTATICA* L1, LISTA_LIGADA_ESTATICA* L2, LISTA_LIGADA_ESTATICA* LC){
    int i = L1->inicio;
    int j = L2->inicio;
    int k = LC->inicio;
    
    while(i != -1){
        LC->A[k].reg.l = L1->A[i].reg.l;
        LC->A[k].proximo = k + 1;
        k++;
        i = L1->A[i].proximo;
    }
    
    while(j != -1){
        LC->A[k].reg.l = L2->A[j].reg.l;
        LC->A[k].proximo = k + 1;
        k++;
        j = L2->A[j].proximo;
    }
    
    LC->A[k - 1].proximo = -1;
}

void intercalar_listas(LISTA_LIGADA_ESTATICA* L1, LISTA_LIGADA_ESTATICA* L2, LISTA_LIGADA_ESTATICA* LI){
    int i = L1->inicio;
    int j = L2->inicio;
    int k = LI->inicio;
    
    while(i != -1 && j != -1){
        LI->A[k].reg.l = L1->A[i].reg.l;
        LI->A[k].proximo = k + 1;
        k++;
        i = L1->A[i].proximo;
        
        LI->A[k].reg.l = L2->A[j].reg.l;
        LI->A[k].proximo = k + 1;
        k++;
        j = L2->A[j].proximo;
    }
    
    while(i != -1){
        LI->A[k].reg.l = L1->A[i].reg.l;
        LI->A[k].proximo = k + 1;
        k++;
        i = L1->A[i].proximo;
    }
    
    while(j != -1){
        LI->A[k].reg.l = L2->A[j].reg.l;
        LI->A[k].proximo = k + 1;
        k++;
        j = L2->A[j].proximo;
    }
    
    LI->A[k - 1].proximo = -1;
}

