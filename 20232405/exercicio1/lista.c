#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"


Lista* Criar_Lista(int i){
	Lista* a= (Lista*) malloc(sizeof(Lista));
	a->n=i;
	a->V=(int*) malloc(i*sizeof(int));
	return a;
}
void Limpar_Lista(Lista* P){
	free(P);
}
void Ler_Lista(Lista* a){
	int d;
	for(d=0;d< a->n ;d++){
		scanf("%d",a->V+d);
	}
}
void LerOrd_Lista(Lista* a){
	int d;
	for(d=0;d< a->n ;d++){
		int b=0;
		while(b==0){
		scanf("%d",a->V+d);
		if(*(a->V+d) <*(a->V+d-1) && d>=1){
			printf("Coloque em ordem crescente!\n");
			b=0;
		}else{
			b=1;
		}
	}
	}
}
void Printar_ListaIterativo(Lista* a){
	int d;
	printf("Termos da lista:\n");
for(d=0;d< a->n ;d++){
		printf("%d\n",*(a->V+d));
	}
}
void Printar_ListaRecursivo(Lista* a,int tamanho){
	if(tamanho==0){
		return;
	}
	Printar_ListaRecursivo(a,tamanho-1);
	printf("%d ",*(a->V+ tamanho-1 ));
}
int Busca_Sequencial(Lista *p, int a){
	int i;
	int comparacao=0;
	for(i=0;i<p->n;i++){
		comparacao++;
		if(a==*(p->V + i)){
			printf("Essa busca Sequencial usou %d comparacoes\n",comparacao);
			return i+1;
		}
	}
	printf("Essa busca Sequencial usou %d comparacoes\n",comparacao);
	return -1;
}
int Busca_SequencialOrd(Lista *p, int a){
	int i;
	int comparacao=0;
	for(i=0;i<p->n;i++){
		comparacao++;
		if(a==*(p->V + i)){
			printf("Essa busca Sequencial Ordenada usou %d comparacoes\n",comparacao);
			return i+1;
		}
		if(a<*(p->V + i)){
			printf("Essa busca Sequencial Ordenada usou %d comparacoes\n",comparacao);
			return -1;
		}
	}
	printf("Essa busca Sequencial Ordenada usou %d comparacoes\n",comparacao);
	return -1;
}
int BuscaBinaria_iterativa(Lista *a, int e){
	int fim=(a->n)-1;
	int i=0;
	int comparacao=0;
	while(i<=fim){
		comparacao++;
		int meio=(i+fim)/2;
		if(*(a->V + meio)==e){
			printf("Essa busca binaria iterativa usou %d comparacoes\n",comparacao);
			return meio+1;
		}
		if(*(a->V + meio)<e){
			i=meio+1;
		}else{
			fim=meio-1;
		}
	}
	printf("Essa busca binaria iterativa usou %d comparacoes\n",comparacao);
	return -1;
}
int BuscaBinariaRecursiva(Lista *p, int e,int fim,int inicio,int *comparacao){
	
	if(inicio<=fim){
		int meio=(inicio+fim)/2;
		(*comparacao)++;
		if(*(p->V+ meio)==e){
		printf("Essa busca binaria recursiva usou %d comparacoes\n",*comparacao);
			return meio+1;
		}
		if(*(p->V+ meio)<e){
			return BuscaBinariaRecursiva(p,e,fim,meio+1,comparacao);
		}else{
			return BuscaBinariaRecursiva(p,e,meio-1,inicio,comparacao);
		}
	}
	printf("Essa busca binaria recursiva usou %d comparacoes\n",*comparacao);	
	return -1;
}
int Maior(Lista *P){
	int i,maior;
	for(i=0;i<P->n;i++){
		if(i==0){
			maior=*(P->V);
		}
		if(*(P->V + i)>maior){
			maior=*(P->V + i);
		}
	}
	return maior;
}
int Menor(Lista *P){
	int i,menor;
	for(i=0;i<P->n;i++){
		if(i==0){
			menor=*(P->V);
		}
		if(*(P->V + i)<menor){
			menor=*(P->V + i);
		}
	}
	return menor;
}
int Soma(Lista *P){
	int i,Soma=0;
	for(i=0;i<P->n;i++){
		Soma=Soma+*(P->V +i);
	}
	return Soma;
}
int Produto(Lista *P){
	int i,Produto;
	for(i=0;i<P->n;i++){
		if(i==0){
			Produto=*(P->V);
		}else{
			Produto=Produto * *(P->V + i);
		}
	}
	return Produto;
}
int MaiorRecursivo(Lista *P, int inicio, int fim){
	if(inicio==fim){
		return *(P->V + inicio);
	}
	int meio=(inicio+fim)/2;
	int maiorEsquerda= MaiorRecursivo(P,inicio,meio);
	int maiorDireita= MaiorRecursivo(P,meio+1,fim);
	if(maiorEsquerda>maiorDireita){
		return maiorEsquerda;
	}else{
		return maiorDireita;
	}
}
int MenorRecursivo(Lista *P, int inicio, int fim){
	if(inicio==fim){
		return *(P->V + inicio);
	}
	int meio=(inicio+fim)/2;
	int menorEsquerda= MenorRecursivo(P,inicio,meio);
	int menorDireita= MenorRecursivo(P,meio+1,fim);
	if(menorEsquerda<menorDireita){
		return menorEsquerda;
	}else{
		return menorDireita;
	}
}
int SomaRecursivo(Lista *P,int inicio, int fim){
	if(inicio>fim){
		return 0;
	}
	int valorAtual = *(P->V +inicio);
	int somaRestante = SomaRecursivo(P,inicio+1,fim);
	return valorAtual+somaRestante;
}
int ProdutoRecursivo(Lista *P, int inicio, int fim){
	if(inicio>fim){
		return 1;
	}
	int valorAtual=*(P->V+inicio);
	int restante=ProdutoRecursivo(P,inicio+1,fim);
	return valorAtual*restante;
}
