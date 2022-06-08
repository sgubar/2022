#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"

int main()
{
    Tree* tree = createTree();

    inputElement(tree);
    printTree(tree);

    delElement(tree);
    printTree(tree);

    deleteTree(tree);
}