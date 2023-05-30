#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
	Lista *a,*b;
	int i=0,d=0,aux=7,comparacao=0;
	printf("Quantos termos nessa lista:\n");
	scanf("%d",&i);
	a=Criar_Lista(i);
	b=Criar_Lista(aux);
	printf("Coloque os termos da lista 1:\n");
	Ler_Lista(a);
	Printar_ListaIterativo(a);
	printf("\nQual termo deseja buscar dentro da lista:\n");
	scanf("%d",&d);
	printf("(Busca Sequencial)O termo procurado esta na posicao:%d\n",Busca_Sequencial(a,d));
	printf("Coloque os termos da lista 2(na ordem crescente!):\n");
	LerOrd_Lista(b);
	printf("\nPrint com algoritmo iterativo:\n");
	Printar_ListaIterativo(b);
	printf("Print com algoritmo recursivo:\n");
	
	Printar_ListaRecursivo(b,b->n);
	printf("\nQual termo deseja buscar dentro da lista 2:\n");
	scanf("%d",&d);
	printf("(Busca Sequencial)O termo procurado esta na posicao:%d\n",Busca_Sequencial(b,d));
	printf("(Busca Sequencial ordenada)O termo procurado esta na posicao:%d\n",Busca_SequencialOrd(b,d));
	printf("(Busca binaria recursiva)O termo procurado esta na posicao:%d\n",BuscaBinariaRecursiva(b,d,aux-1,0,&comparacao));
	printf("(Busca binaria iterativa)O termo procurado esta na posicao:%d\n",BuscaBinaria_iterativa(b,d));
	
	printf("O maior elemento da lista 1(iterativo):%d\n",Maior(a));
	printf("O maior elemento da lista 1(Recursivo):%d\n",MaiorRecursivo(a,0,a->n-1));
	printf("O menor elemento da lista 1(iterativo):%d\n",Menor(a));
	printf("O menor elemento da lista 1(Recursivo):%d\n",MenorRecursivo(a,0,a->n-1));
	printf("A Soma dos elementos da lista 1(iterativo):%d\n",Soma(a));
	printf("A Soma dos elementos da lista 1(Recursivo):%d\n",SomaRecursivo(a,0,a->n-1));
	printf("O produto dos elementos da lista 1(iterativo):%d\n",Produto(a));
	printf("O produto dos elementos da lista 1(Recursivo):%d\n",ProdutoRecursivo(a,0,a->n-1));
	printf("(Busca binaria recursiva)O termo procurado esta na posicao:%d\n",BuscaBinariaRecursiva(a,2,a->n-1,0,&comparacao));
	Limpar_Lista(a);
	Limpar_Lista(b);
}


