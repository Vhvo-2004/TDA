#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};

struct AVLTree {
    Node* root;
};

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

AVLTree* createAVLTree() {
    AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->root = NULL;
    return tree;
}

void destroyNode(Node* node) {
    if (node == NULL)
        return;
    destroyNode(node->left);
    destroyNode(node->right);
    free(node);
}

void destroyAVLTree(AVLTree* tree) {
    if (tree == NULL)
        return;
    destroyNode(tree->root);
    free(tree);
}

int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

Node* rebalance(Node* node) {
    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (getBalanceFactor(node->left) >= 0)
            return rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balance < -1) {
        if (getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

Node* insertNode(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node; // Duplicate keys are not allowed in AVL Tree.

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    return rebalance(node);
}

void insert(AVLTree* tree, int key) {
    if (tree == NULL)
        return;
    tree->root = insertNode(tree->root, key);
}

void printInOrder(Node* node) {
    if (node == NULL)
        return;
    printInOrder(node->left);
    printf("%d ", node->key);
    printInOrder(node->right);
}
void printPreOrder(Node* node) {
    if (node == NULL)
        return;
        printf("%d ", node->key);
    printPreOrder(node->left);
    printPreOrder(node->right);
}
void printPosOrder(Node* node) {
    if (node == NULL)
        return;
    printPosOrder(node->left);
    printPosOrder(node->right);
    printf("%d ", node->key);
}
void printTree(AVLTree* tree) {
    if (tree == NULL)
        return;
    printInOrder(tree->root);
    printf("\n");
}
Node* searcher(Node* root , int key){
	if(root==NULL|| root->key==key){
		return root;
	}
	if (key<root->key){
		return searcher(root->left,key);
	}else{
		return searcher(root->right,key);
	}
}
void search(AVLTree* root , int key){
	if(root==NULL){
		return;
	}
	root->root=searcher(root->root,key);
	if(root->root==NULL){
		printf("Nao %d foi encontrado!\n",key);
	}else{
		printf("%d foi encontrado!\n",key);
	}
}

