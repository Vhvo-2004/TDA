#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

typedef struct {
    int elementos[TAM_MAX];
    int tamanho;
} ListaLinearInt;

void criarListaInt(ListaLinearInt *lista) {
    lista->tamanho = 0;
}

void inserirElementoInt(ListaLinearInt *lista, int elemento) {
    if (lista->tamanho < TAM_MAX) {
        lista->elementos[lista->tamanho] = elemento;
        lista->tamanho++;
    } else {
        printf("A lista está cheia. Não é possível inserir o elemento.\n");
    }
}

void inserirElementoOrdenadoInt(ListaLinearInt *lista, int elemento) {
    int i, j;

    if (lista->tamanho == 0) {
        lista->elementos[0] = elemento;
        lista->tamanho++;
        return;
    }

    if (lista->tamanho >= TAM_MAX) {
        printf("A lista está cheia. Não é possível inserir o elemento.\n");
        return;
    }

    for (i = 0; i < lista->tamanho; i++) {
        if (elemento < lista->elementos[i]) {
            for (j = lista->tamanho - 1; j >= i; j--) {
                lista->elementos[j + 1] = lista->elementos[j];
            }
            lista->elementos[i] = elemento;
            lista->tamanho++;
            return;
        }
    }

    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
}

int obterQuantidadeElementosInt(ListaLinearInt lista) {
    return lista.tamanho;
}

int buscarSequencialInt(ListaLinearInt lista, int elemento) {
    int i;

    for (i = 0; i < lista.tamanho; i++) {
        if (lista.elementos[i] == elemento) {
            return i;
        }
    }

    return -1; // Elemento não encontrado
}

int buscarBinariaInt(ListaLinearInt lista, int elemento) {
    int baixo, alto, meio;

    baixo = 0;
    alto = lista.tamanho - 1;

    while (baixo <= alto) {
        meio = (baixo + alto) / 2;
        if (elemento == lista.elementos[meio]) {
            return meio;
        } else if (elemento < lista.elementos[meio]) {
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }

    return -1; // Elemento não encontrado
}

void excluirElementoPorPosicaoInt(ListaLinearInt *lista, int posicao) {
    int i;

    if (posicao >= 0 && posicao < lista->tamanho) {
        for (i = posicao; i < lista->tamanho - 1; i++) {
            lista->elementos[i] = lista->elementos[i + 1];
        }
        lista->tamanho--;
    } else {
        printf("Posição inválida. Não é possível excluir o elemento.\n");
    }
}

void imprimirElementosInt(ListaLinearInt lista) {
    int i;

    printf("Elementos da lista: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i]);
    }
    printf("\n");
}
int main(){
	ListaLinearInt A;
	criarListaInt(&A);
	inserirElementoInt(&A,0);
	
	imprimirElementosInt(A);
	
	return 0;
}
