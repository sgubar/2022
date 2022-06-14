#include "tree.h"

TreePtr create_tree()
{
    TreePtr new = (TreePtr)calloc(1, sizeof(Tree));

    return new;
};
NodePtr create_node(double value, NodePtr left, NodePtr right)
{
    NodePtr new = calloc(1, sizeof(Node));

    new->value = value;
    new->left = left;
    new->right = right;
    
    return new;
}
NodePtr search_element(TreePtr tree, double sval)
{
    NodePtr current = tree->root;

    while (1)
    {
        if(current == NULL)
            return NULL;

        if(current->value == sval)
        {
            return current;
        }
        else if(current->value > sval)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    } 
};
NodePtr insert_element(TreePtr tree, double ival)
{
    NodePtr *parent = &tree->root;
    NodePtr curr = tree->root;

    while(1)
    {
        if(curr == NULL)
        {
            *parent = create_node(ival, NULL, NULL);
            return curr;
        }
        else if(curr->value == ival)
        {
            // tree already contains element with this value
            return curr;
        }
        else if(curr->value > ival)
        {
            parent = &curr->left;
            curr = curr->left;
        }
        else
        {
            parent = &curr->right;
            curr = curr->right;
        }
    }
};
void delete_tree(TreePtr* tree)
{
    delete_subtree(&((*tree)->root));
    free(*tree);
    *tree = NULL;
};
void delete_recursive(NodePtr root)
{
    if(root == NULL)
    {
        return;
    }

    delete_recursive(root->left);
    delete_recursive(root->right);

    if(root->left == NULL && root->right == NULL)
    {
        free(root);
    }
};
void delete_subtree(NodePtr* ptr)
{
    delete_recursive(*ptr);
    *ptr = NULL;
};
void delete_element(TreePtr tree, double dval);
void print_tree(TreePtr tree);