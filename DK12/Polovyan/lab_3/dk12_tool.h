#ifndef dk12_tool_h
#define dk12_tool_h
#include <stdio.h>
#include <stdlib.h>

typedef struct __node intNode;
struct __node //гілки дерева
{
	int value;
	intNode *leftChild;
	intNode *rightChild;
};

typedef struct __tree // елементи дерева
{
	intNode *root;
	int count;
} intTree;

intTree *createIntTree();										  // створення дерева
void deleteIntTree(intTree *aTree);							  // видалення дерева
void printTree(intNode *aRoot);								  // вивід дерева
void insertIntValueToTree(intTree *aTree, int aValue);  // вставка елемента у дерево
int deleteValueFromTree(intTree *aTree, int aValue);	  // видалення елемента з дерева
intNode *findNodeWithValue(intTree *aTree, int aValue); // пошук елемента у дереві по значенню

#endif
