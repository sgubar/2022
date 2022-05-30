#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"

int main()
{
    Tree* tree = createTree();

    addElement(tree, 10);
    addElement(tree, 7);
    addElement(tree, 4);
    addElement(tree, 9);
    addElement(tree, 2);
    addElement(tree, 6);
    addElement(tree, 5);
    printTree(tree);

    delElementByValue(tree, 7);
    printTree(tree);

    deleteTree(tree);
}