#define _CRT_SECURE_NO_WARNINGS
#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>
#include <stdlib.h>

typedef struct __node doubleNode;
struct __node
{
	double value;
	doubleNode* leftChild;
	doubleNode* rightChild;
};
typedef struct __tree
{
	doubleNode* root;
	double count;
} doubleTree;

doubleTree* createDoubleTree();
void deleteDoubleTree(doubleTree* aTree);

void printTree(doubleNode* aRoot);
void insertValue(doubleTree* aTree, double aValue);
double deleteValue(doubleTree* aTree, double aValue);

doubleNode* FindNodeValue(doubleTree* aTree, double aValue);

#endif
