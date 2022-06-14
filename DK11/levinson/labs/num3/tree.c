#include "tree.h"

#pragma region Internal_Utility

NodePtr create_node(double value, NodePtr left, NodePtr right)
{
    NodePtr new = calloc(1, sizeof(Node));

    new->value = value;
    new->left = left;
    new->right = right;
    
    return new;
}
NodePtr search_parent(TreePtr tree, NodePtr node)
{
    double sval = node->value;
    NodePtr current = tree->root;

    while (1)
    {
        if(current == NULL)
        {
            printf("No element containing value '%2.2f' has been found.", sval);
            return NULL;
        }
        if(current->value == sval)
        {
            printf("Singleton tree passed to search_parent.");
            return NULL;
        }
        else if(current->left->value == sval || current->right->value == sval)
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
}
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
}
NodePtr reconstruct_branch(NodePtr node)
{
    // this function takes in pointer to a node that
}
#pragma endregion

TreePtr create_tree()
{
    TreePtr new = (TreePtr)calloc(1, sizeof(Tree));

    return new;
}
NodePtr search_element(TreePtr tree, double sval)
{
    NodePtr current = tree->root;

    while (1)
    {
        if(current == NULL)
        {
            printf("Empty tree passed to search_element.");
            return NULL;
        }

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
}
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
}
void delete_tree(TreePtr* tree)
{
    delete_subtree(&((*tree)->root));
    free(*tree);
    *tree = NULL;
}
void delete_subtree(NodePtr* ptr)
{
    delete_recursive(*ptr);
    *ptr = NULL;
}
void delete_element(TreePtr tree, NodePtr *n)
{
    NodePtr node = *n;

    if(node->left == NULL && node->right == NULL)
    {
        free(node);
        node = NULL;
    }
    if(node->left == NULL && node->right != NULL)
    {
        NodePtr parent = search_parent(tree, node);

        if(parent->left->value == node->value)
        {
            parent->left = node->right;
        }
        else
        {
            parent->right = node->right;
        }

        free(node);
        node = NULL;
    }
    if(node->left != NULL && node->right == NULL)
    {
        NodePtr parent = search_parent(tree, node);

        if(parent->left->value == node->value)
        {
            parent->left = node->left;
        }
        else
        {
            parent->right = node->left;
        }
    }


}
void print_tree_inorder(NodePtr root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        printf("[ %2.2f ] ", root->value);
        return;
    }

    print_tree_inorder(root->left);
    printf("[ %2.2f ] ", root->value);
    print_tree_inorder(root->right);
}