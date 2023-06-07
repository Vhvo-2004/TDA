#include<stdio.h>
#include "listou.h"

int main(){
    LISTA_LIGADA_ESTATICA lista1, lista2, listaC, listaI;
    
    inicializarLista(&lista1);
    inicializarLista(&lista2);
    inicializarLista(&listaC);
    inicializarLista(&listaI);
    
    formar_lista(&lista1);
    formar_lista(&lista2);
    
    printf("Lista 1:\n");
    exibir_lista(&lista1);
    
    printf("Lista 2:\n");
    exibir_lista(&lista2);
    
    copiar_lista(&lista1, &lista2);
    printf("Copia da Lista 1 para Lista 2:\n");
    exibir_lista(&lista2);
    
    concatenar_listas(&lista1, &lista2, &listaC);
    printf("Concatenacao da Lista 1 e Lista 2:\n");
    exibir_lista(&listaC);
    
    intercalar_listas(&lista1, &lista2, &listaI);
    printf("Intercalacao da Lista 1 e Lista 2:\n");
    exibir_lista(&listaI);
    
    return 0;
}

