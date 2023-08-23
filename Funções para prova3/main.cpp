#include <stdio.h>
#include "binary_search_tree.h"

int main() {
    // Criação da árvore de busca binária
    Tree* tree = createTree();

    // Inserção de valores na árvore
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);

    // Impressão da árvore em diferentes ordens
    printf("Arvore em ordem crescente:\n");
    printInOrder(tree);

    printf("Arvore em pre-ordem:\n");
    printPreOrder(tree);

    printf("Arvore em pos-ordem:\n");
    printPosOrder(tree);

    // Busca por um valor na árvore
    int valueToSearch = 40;
    int found = search(tree, valueToSearch);

    if (found)
        printf("Valor %d encontrado na arvore.\n", valueToSearch);
    else
        printf("Valor %d não encontrado na arvore.\n", valueToSearch);

    // Liberação de memória
    destroyTree(tree);

    return 0;
}

