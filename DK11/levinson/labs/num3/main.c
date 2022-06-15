#include "tree.h"

int main(void)
{
    TreePtr tree = create_tree();
    insert_element(tree, 5);
    insert_element(tree, 2);
    insert_element(tree, 1);
    insert_element(tree, 4);
    insert_element(tree, 8);
    insert_element(tree, 10);
    insert_element(tree, 3);
    insert_element(tree, 7);
    insert_element(tree, 9);

    print_tree(tree);

    delete_element(tree, search_element(tree, 2));
    print_tree(tree);

    delete_element(tree, search_element(tree, 8));
    print_tree(tree);

    delete_element(tree, tree->root);
    print_tree(tree);

    delete_element(tree, search_element(tree, 1));
    print_tree(tree);

    delete_subtree(&tree->root->left);
    print_tree(tree);

    delete_tree(&tree);
    print_tree(tree);

    return 0;
}
