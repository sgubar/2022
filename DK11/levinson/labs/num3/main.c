#include "tree.h"
#include <string.h>

int main(void)
{
    char c;
    char input_text[21];
    double input_double;
    int index;

    printf("\nWelcome to the BST demo program! Do you wish to proceed (y/n)?\n");
    scanf(" %c", &c);

    if(c != 'y')
    {
        return 0;
    }

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

    printf("\nYou can now manipulate this BST, type any valid command or 'man' to get a list of available commands.\n\n");

    while(strcmp(input_text, "quit") != 0 && tree != NULL)
    {
        memset(input_text, 0, sizeof(char) * 21);
        scanf("%20s", input_text);
        
        if(strcmp(input_text, "man") == 0)
        {
            printf("\n\nAvailable commands:\n\n'insert [double]' - inserts [double] into an appropriate place in the tree.\n\n'delete_element [double]' - finds node such that node->value == [double] and deletes it.\n\n'delete_branch [double]' - finds node such that node->value == [double] and deletes it and all the nodes downstream from it.\n\n'print' - completes an inorder traversal of the tree printing out all the node values to stdout.\n\n");
        }
        else if(strcmp(input_text, "insert") == 0)
        {
            scanf("%lf", &input_double);

            insert_element(tree, input_double);
        }
        else if(strcmp(input_text, "delete_element") == 0)
        {
            scanf("%lf", &input_double);

            delete_element(tree, search_element(tree, input_double));
        }
        else if(strcmp(input_text, "delete_branch") == 0)
        {
            scanf("%lf", &input_double);

            delete_subtree(&tree, search_element(tree, input_double));
        }
        else if(strcmp(input_text, "print") == 0)
        {
            print_tree(tree);
        }
        else if(strcmp(input_text, "quit") == 0)
        {
            delete_tree(&tree);
        }
        else
        {
            printf("\nInvalid input: %s; Use 'man' command to get a list of valid commands.\n\n", input_text);
        }
    }

    printf("\nThanks for using BST demo program.\n");

    return 0;
}
void test(void)
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

    delete_subtree(tree, tree->root->left);
    print_tree(tree);

    delete_tree(tree);
    print_tree(tree);
}