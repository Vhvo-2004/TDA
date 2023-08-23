#include <stdio.h>
#include "avl_tree.h"

int main() {
    // Criação da árvore AVL
    AVLTree* tree = createAVLTree();

    // Inserção de valores na árvore
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);

    printf("Árvore AVL em ordem crescente:\n");
    printTree(tree);

    // Busca por um valor na árvore
    int valueToSearch = 90;
    search(tree, valueToSearch);

    

    // Liberação de memória
    destroyAVLTree(tree);

    return 0;
}

