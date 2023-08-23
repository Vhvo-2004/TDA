#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node Node;
typedef struct Tree Tree;

// Cria uma nova árvore de busca binária
Tree* createTree();

// Insere um novo valor na árvore de busca binária
void insert(Tree* tree, int value);

// Realiza a busca por um valor na árvore de busca binária
int search(Tree* tree, int value);

// Imprime a árvore em ordem crescente (in ordem)
void printInOrder(Tree* tree);

// Imprime a árvore em pré-ordem
void printPreOrder(Tree* tree);

// Imprime a árvore em pós-ordem
void printPosOrder(Tree* tree);

// Libera a memória alocada pela árvore
void destroyTree(Tree* tree);

#endif // BINARY_SEARCH_TREE_H

