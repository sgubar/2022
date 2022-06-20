#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
      float value;
      struct Element *left;
      struct Element *right;
} Element;

typedef struct tree
{
      Element *root;
} tree;

tree *createTree();
void deleteTree(tree *aTree);

Element *createElement(float Value);
void destroyElement(Element *El);
Element *findElement(tree *aTree, float Value);
void insertElement(tree *aTree, float Value);
void deleteElement(tree *aTree, float Value);
void printTree(tree *aTree);
#endif