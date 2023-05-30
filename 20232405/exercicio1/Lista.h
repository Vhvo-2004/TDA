#ifndef Lista_H
#define Lista_H
typedef struct{
	int n;
	int *V;
}Lista;

Lista* Criar_Lista(int i);
void Ler_Lista(Lista* i);
void LerOrd_Lista(Lista* i);
void Limpar_Lista(Lista* P);
void Printar_ListaIterativo(Lista* Print);
void Printar_ListaRecursivo(Lista* Print,int tamanho);
int Busca_Sequencial(Lista *P, int a);
int Busca_SequencialOrd(Lista *P, int a);
int BuscaBinaria_iterativa(Lista *P,int e);
int BuscaBinariaRecursiva(Lista *p, int e,int fim,int inicio, int *comparacao);
int Maior(Lista *P);
int Menor(Lista *P);
int Soma(Lista *P);
int Produto(Lista *P);
int MaiorRecursivo(Lista *P, int inicio, int fim);
int MenorRecursivo(Lista *P, int inicio, int fim);
int SomaRecursivo(Lista *P,int inicio, int fim);
int ProdutoRecursivo(Lista *P,int inicio, int fim);
#endif
