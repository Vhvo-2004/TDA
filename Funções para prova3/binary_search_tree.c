#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

struct Node {
    int value;
    Node* left;
    Node* right;
};

struct Tree {
    Node* root;
};

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
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

void destroyTree(Tree* tree) {
    if (tree == NULL)
        return;
    destroyNode(tree->root);
    free(tree);
}

Node* insertNode(Node* node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->value)
        node->left = insertNode(node->left, value);
    else if (value > node->value)
        node->right = insertNode(node->right, value);

    return node;
}

void insert(Tree* tree, int value) {
    if (tree == NULL)
        return;
    tree->root = insertNode(tree->root, value);
}

int searchNode(Node* node, int value) {
    if (node == NULL)
        return 0;

    if (node->value == value)
        return 1;
    else if (value < node->value)
        return searchNode(node->left, value);
    else
        return searchNode(node->right, value);
}

int search(Tree* tree, int value) {
    if (tree == NULL)
        return 0;
    return searchNode(tree->root, value);
}

void printInOrderNode(Node* node) {
    if (node == NULL)
        return;
    printInOrderNode(node->left);
    printf("%d ", node->value);
    printInOrderNode(node->right);
}

void printInOrder(Tree* tree) {
    if (tree == NULL)
        return;
    printInOrderNode(tree->root);
    printf("\n");
}

void printPreOrderNode(Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->value);
    printPreOrderNode(node->left);
    printPreOrderNode(node->right);
}

void printPreOrder(Tree* tree) {
    if (tree == NULL)
        return;
    printPreOrderNode(tree->root);
    printf("\n");
}

void printPosOrderNode(Node* node) {
    if (node == NULL)
        return;
    printPosOrderNode(node->left);
    printPosOrderNode(node->right);
    printf("%d ", node->value);
}

void printPosOrder(Tree* tree) {
    if (tree == NULL)
        return;
    printPosOrderNode(tree->root);
    printf("\n");
}

