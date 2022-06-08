#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode Node;
struct tagNode
{
    int value;
    Node *leftChild;
    Node *rightChild;
};

typedef struct tagTree
{
    Node *root;
    int count;
} Tree;

Tree *createTree();
void deleteTree(Tree *aTree);
void printTree(Node *aRoot);
void insertValueToTree(Tree *aTree, int aValue);
int deleteValueFromTree(Tree *aTree, int aValue);
Node *findNodeWithValue(Tree *aTree, int aValue);

#endif
