#ifndef dk12_tool_h
#define dk12_tool_h
#include <stdio.h>
#include <stdlib.h>

typedef struct __node floatNode;
struct __node //гілки дерева
{
	float value;
	floatNode *leftChild;
	floatNode *rightChild;
};

typedef struct __tree // елементи дерева
{
	floatNode *root;
	float count;
} floatTree;


floatTree *createFloatTree();										  // створення дерева
void deleteFloatTree(floatTree *aTree);							  // видалення дерева
void printTree(floatNode *aRoot);								  // вивід дерева
void insertFloatValueToTree(floatTree *aTree, float aValue);  // вставка елемента у дерево
float deleteValueFromTree(floatTree *aTree, float aValue);	  // видалення елемента з дерева
floatNode *findNodeWithValue(floatTree *aTree, float aValue); // пошук елемента у дереві по значенню

#endif
