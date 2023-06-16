#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

typedef struct {
    Node* inicio;
} ListaLigadaDinamicaInt;

void inicializar(ListaLigadaDinamicaInt* lista) {
    lista->inicio = NULL;
}

void limpar_lista(ListaLigadaDinamicaInt* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}

void inserir_elemento(ListaLigadaDinamicaInt* lista, int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro: impossível alocar memória.\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        Node* atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void inserir_elemento_ordenado(ListaLigadaDinamicaInt* lista, int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro: impossível alocar memória.\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (lista->inicio == NULL || valor < lista->inicio->valor) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } else {
        Node* atual = lista->inicio;
        Node* anterior = NULL;

        while (atual != NULL && valor > atual->valor) {
            anterior = atual;
            atual = atual->prox;
        }

        anterior->prox = novo;
        novo->prox = atual;
    }
}

int contar_elementos(ListaLigadaDinamicaInt* lista) {
    int count = 0;
    Node* atual = lista->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

int buscar_sequencial(ListaLigadaDinamicaInt* lista, int valor) {
    int posicao = 0;
    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }
        posicao++;
        atual = atual->prox;
    }
    return -1; // valor não encontrado
}

void excluir_elemento(ListaLigadaDinamicaInt* lista, int valor) {
    Node* atual = lista->inicio;
    Node* anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                lista->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Valor não encontrado na lista.\n");
}

void exibir(ListaLigadaDinamicaInt* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

void ordenar_lista(ListaLigadaDinamicaInt* lista_origem, ListaLigadaDinamicaInt* lista_destino) {
    // Limpa a lista de destino antes de inserir os elementos
    limpar_lista(lista_destino);

    // Percorre a lista de origem
    Node* atual = lista_origem->inicio;
    while (atual != NULL) {
        // Insere o elemento na lista de destino de forma ordenada
        inserir_elemento_ordenado(lista_destino, atual->valor);

        atual = atual->prox;
    }
}

int main() {
    ListaLigadaDinamicaInt lista_origem, lista_destino;
    inicializar(&lista_origem);
    inicializar(&lista_destino);

    // Insere elementos na lista de origem
    inserir_elemento(&lista_origem, 5);
    inserir_elemento(&lista_origem, 2);
    inserir_elemento(&lista_origem, 7);
    inserir_elemento(&lista_origem, 3);

    // Ordena a lista de origem e armazena o resultado na lista de destino
    ordenar_lista(&lista_origem, &lista_destino);

    // Exibe a lista de origem
    printf("Lista de Origem:\n");
    exibir(&lista_origem);
    printf("Tamanho da lista de Origem: %d\n", contar_elementos(&lista_origem));

    printf("\n");

    // Exibe a lista de destino (lista ordenada)
    printf("Lista Ordenada:\n");
    exibir(&lista_destino);
    printf("Tamanho da lista Ordenada: %d\n", contar_elementos(&lista_destino));

    return 0;
}

