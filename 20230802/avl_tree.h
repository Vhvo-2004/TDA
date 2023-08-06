#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct Node Node;
typedef struct AVLTree AVLTree;

AVLTree* createAVLTree();
void destroyAVLTree(AVLTree* tree);

int getHeight(Node* node);
int getBalanceFactor(Node* node);

Node* rotateRight(Node* node);
Node* rotateLeft(Node* node);
Node* rebalance(Node* node);

Node* insertNode(Node* node, int key);
void insert(AVLTree* tree, int key);

void printInOrder(Node* node);
void printTree(AVLTree* tree);

#endif // AVL_TREE_H

