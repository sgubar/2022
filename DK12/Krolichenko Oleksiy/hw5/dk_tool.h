#ifndef dk_tool_h
#define dk_tool_h
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node doubleNode;
struct __node {
	double value;
	doubleNode* l;
	doubleNode* r;
};

typedef struct __tree {
	doubleNode* root;
	double count;
} doubleTree;

doubleTree* createTree();
void insertValue(doubleTree* tree, double value);
double deleteValue(doubleTree* tree, double value);
doubleNode* findValue(doubleTree* tree, double value);
void printTree(doubleNode* root);
void deleteTree(doubleTree* tree);

#endif