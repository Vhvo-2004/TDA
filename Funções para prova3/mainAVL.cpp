#include <stdio.h>
#include "avl_tree.h"

int main() {
    // Cria��o da �rvore AVL
    AVLTree* tree = createAVLTree();

    // Inser��o de valores na �rvore
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);

    printf("�rvore AVL em ordem crescente:\n");
    printTree(tree);

    // Busca por um valor na �rvore
    int valueToSearch = 90;
    search(tree, valueToSearch);

    

    // Libera��o de mem�ria
    destroyAVLTree(tree);

    return 0;
}

