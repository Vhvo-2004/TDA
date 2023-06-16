#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura Aluno
typedef struct Aluno {
    int codigo;
    char nome[100];
    int idade;
    int numFilhos;
} Aluno;

// Defini��o da estrutura Node que representa um n� da lista ligada
typedef struct Node {
    Aluno aluno;          // Dados do Aluno armazenados no n�
    struct Node* prox;    // Ponteiro para o pr�ximo n� da lista
} Node;

// Defini��o da estrutura ListaLigadaDinamicaAluno que representa a lista ligada
typedef struct {
    Node* inicio;    // Ponteiro para o primeiro n� da lista
} ListaLigadaDinamicaAluno;

// Inicializa a lista, definindo o in�cio como NULL
void inicializar(ListaLigadaDinamicaAluno* lista) {
    lista->inicio = NULL;
}

// Libera a mem�ria ocupada pela lista, percorrendo e desalocando cada n�
void limpar_lista(ListaLigadaDinamicaAluno* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}

// Insere um novo aluno no final da lista
void inserir_elemento(ListaLigadaDinamicaAluno* lista, Aluno aluno) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro: imposs�vel alocar mem�ria.\n");
        return;
    }
    novo->aluno = aluno;
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

// Retorna a quantidade de elementos na lista, percorrendo a lista e contando os n�s
int contar_elementos(ListaLigadaDinamicaAluno* lista) {
    int count = 0;
    Node* atual = lista->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

// Busca sequencialmente um aluno na lista pelo c�digo
// Retorna o n� que cont�m o aluno encontrado ou NULL se n�o encontrado
Node* buscar_sequencial(ListaLigadaDinamicaAluno* lista, int codigo) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->aluno.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; // aluno n�o encontrado
}

// Busca bin�ria de um aluno na lista pelo c�digo
// Retorna o n� que cont�m o aluno encontrado ou NULL se n�o encontrado
Node* buscar_binaria(ListaLigadaDinamicaAluno* lista, int codigo) {
    int esquerda = 0;
    int direita = contar_elementos(lista) - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        Node* atual = lista->inicio;
        // Move o ponteiro atual para o meio da lista
        for (int i = 0; i < meio; i++) {
            atual = atual->prox;
        }

        if (atual->aluno.codigo == codigo) {
            return atual;
        } else if (atual->aluno.codigo < codigo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return NULL; // aluno n�o encontrado
}

// Exclui um aluno da lista pela posi��o (�ndice)
void excluir_elemento_posicao(ListaLigadaDinamicaAluno* lista, int posicao) {
    if (posicao < 0 || posicao >= contar_elementos(lista)) {
        printf("Posi��o inv�lida.\n");
        return;
    }

    if (posicao == 0) {
        Node* primeiro = lista->inicio;
        lista->inicio = primeiro->prox;
        free(primeiro);
    } else {
        Node* anterior = NULL;
        Node* atual = lista->inicio;
        for (int i = 0; i < posicao; i++) {
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = atual->prox;
        free(atual);
    }
}

// Exclui um aluno da lista pelo c�digo
void excluir_elemento_valor(ListaLigadaDinamicaAluno* lista, int codigo) {
    Node* atual = lista->inicio;
    Node* anterior = NULL;
    while (atual != NULL) {
        if (atual->aluno.codigo == codigo) {
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
    printf("Aluno n�o encontrado na lista.\n");
}

// Imprime os elementos da lista
void imprimir_lista(ListaLigadaDinamicaAluno* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        printf("C�digo: %d, Nome: %s, Idade: %d, N�mero de Filhos: %d\n",
               atual->aluno.codigo, atual->aluno.nome, atual->aluno.idade, atual->aluno.numFilhos);
        atual = atual->prox;
    }
}

int main() {
    ListaLigadaDinamicaAluno lista;

    // Inicializa a lista
    inicializar(&lista);

    // Cria alguns alunos
    Aluno aluno1 = { 1, "Jo�o", 20, 0 };
    Aluno aluno2 = { 2, "Maria", 22, 1 };
    Aluno aluno3 = { 3, "Pedro", 19, 0 };

    // Insere os alunos na lista
    inserir_elemento(&lista, aluno1);
    inserir_elemento(&lista, aluno2);
    inserir_elemento(&lista, aluno3);

    // Imprime a lista de alunos
    printf("Lista de Alunos:\n");
    imprimir_lista(&lista);

    // Retorna a quantidade de elementos na lista
    int quantidade = contar_elementos(&lista);
    printf("\nQuantidade de elementos na lista: %d\n", quantidade);

    // Busca sequencialmente um aluno na lista
    int codigo_busca = 2;
    Node* aluno_encontrado = buscar_sequencial(&lista, codigo_busca);
    if (aluno_encontrado != NULL) {
        printf("\nAluno encontrado na busca sequencial:\n");
        printf("Codigo: %d, Nome: %s, Idade: %d, N�mero de Filhos: %d\n",
               aluno_encontrado->aluno.codigo, aluno_encontrado->aluno.nome,
               aluno_encontrado->aluno.idade, aluno_encontrado->aluno.numFilhos);
    } else {
        printf("\nAluno n�o encontrado na busca sequencial.\n");
    }

    // Exclui um aluno da lista pelo c�digo
    int codigo_exclusao = 1;
    excluir_elemento_valor(&lista, codigo_exclusao);

    // Imprime a lista de alunos ap�s a exclus�o
    printf("\nLista de Alunos ap�s a exclus�o:\n");
    imprimir_lista(&lista);

    // Libera a mem�ria ocupada pela lista
    limpar_lista(&lista);

    return 0;
}

