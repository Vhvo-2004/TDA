#include <stdio.h>
#include "avl_tree.h"

int main() {
    AVLTree* tree = createAVLTree();

    int values[] = {1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        insert(tree, values[i]);
    }

    printf("AVL Tree in-order traversal:\n");
    printTree(tree);

    destroyAVLTree(tree);

    return 0;
}

