#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node Node;
typedef struct Tree Tree;

// Cria uma nova �rvore de busca bin�ria
Tree* createTree();

// Insere um novo valor na �rvore de busca bin�ria
void insert(Tree* tree, int value);

// Realiza a busca por um valor na �rvore de busca bin�ria
int search(Tree* tree, int value);

// Imprime a �rvore em ordem crescente (in ordem)
void printInOrder(Tree* tree);

// Imprime a �rvore em pr�-ordem
void printPreOrder(Tree* tree);

// Imprime a �rvore em p�s-ordem
void printPosOrder(Tree* tree);

// Libera a mem�ria alocada pela �rvore
void destroyTree(Tree* tree);

#endif // BINARY_SEARCH_TREE_H

