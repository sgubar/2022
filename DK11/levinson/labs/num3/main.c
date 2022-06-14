#include "tree.h"

int main(int argc, char const *argv[])
{
    TreePtr tree = create_tree();
    insert_element(tree, 5);
    insert_element(tree, 2);
    insert_element(tree, 1);
    insert_element(tree, 4);
    insert_element(tree, 8);
    insert_element(tree, 10);

    print_tree_inorder(tree->root);

    delete_subtree(&tree->root->left);
    delete_tree(&tree);
    return 0;
}
