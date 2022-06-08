#include <stdio.h>
#include "dk_tool.h"

int main()
{
    Tree *tree = createTree();

    insertValueToTree(tree, 3);
    insertValueToTree(tree, 48);
    insertValueToTree(tree, 55);
    insertValueToTree(tree, 11);

    printf("\n");
    printTree(tree->root);

    printf("\n\nNode: %d\n\n", findNodeWithValue(tree, 11)->value);

    deleteValueFromTree(tree, 3);
    deleteValueFromTree(tree, 55);

    printTree(tree->root);
    deleteTree(tree);
    return 1;
}
