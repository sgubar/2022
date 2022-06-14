#ifndef DK12_TOOL_H
#define DK12_TOOL_H

#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BinaryTree
{
    Node* root;
    int count;
} BinaryTree;


BinaryTree* createTree();
void destroyTree(BinaryTree* aTree);

void insert(BinaryTree* tree, int aValue);
Node* find(BinaryTree* tree, int aValue);
void delete(BinaryTree* tree, int aValue);



void print(BinaryTree* tree);

#endif 