#include <stdio.h>
#include "binary_search_tree.h"

int main() {
    // Cria��o da �rvore de busca bin�ria
    Tree* tree = createTree();

    // Inser��o de valores na �rvore
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);

    // Impress�o da �rvore em diferentes ordens
    printf("Arvore em ordem crescente:\n");
    printInOrder(tree);

    printf("Arvore em pre-ordem:\n");
    printPreOrder(tree);

    printf("Arvore em pos-ordem:\n");
    printPosOrder(tree);

    // Busca por um valor na �rvore
    int valueToSearch = 40;
    int found = search(tree, valueToSearch);

    if (found)
        printf("Valor %d encontrado na arvore.\n", valueToSearch);
    else
        printf("Valor %d n�o encontrado na arvore.\n", valueToSearch);

    // Libera��o de mem�ria
    destroyTree(tree);

    return 0;
}

