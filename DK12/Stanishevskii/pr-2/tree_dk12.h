#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#endif

typedef struct tagNode Node;

struct tagNode
{
	int value;
	Node* LChild;
	Node* RChild;
};

typedef struct tagBinTree {
	Node* root;
	int count;
} BinTree;

BinTree* createTree();
void printTree(Node* aNode);
void debugTree(BinTree* ATree);
void destroyTree(BinTree* aTree);
Node* createNode(int aValue);
void destroyNode(Node* aNode);
Node* destroyTreeNode(Node* treeRoot, int aValue);
Node* getaword(Node* treeRoot);
void addNode(BinTree* aTree, int aValue);
Node* findNode(BinTree* aTree, int aValue);
int deleteValueFromTheTree(BinTree* aTree, int aValue);
