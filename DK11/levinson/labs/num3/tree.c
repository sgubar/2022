#include "tree.h"

#pragma region Internal_Utility

NodePtr _create_node(double value)
{
    NodePtr new = calloc(1, sizeof(Node));

    if(new == NULL)
    {
        printf("calloc() has failed to allocate memory.");
        return new;
    }

    new->value = value;
    
    return new;
}
NodePtr _search_parent(TreePtr tree, NodePtr node)
{
    if(tree == NULL || node == NULL)
    {
        printf("Invalid input passed to _search_parent().");
        return NULL;
    }

    double sval = node->value;
    NodePtr current = tree->root;

    while (1)
    {
        if(current == NULL)
        {
            printf("\nNo element containing value '%2.2f' has been found.\n", sval);
            return NULL;
        }
        else if (current->value == sval)
        {
            printf("\nTree root passed to _search_parent() function.\n");
            return NULL;
        }
        else if((current->left != NULL && current->left->value == sval) || (current->right != NULL && current->right->value == sval))
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
void _delete_recursive(NodePtr root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left != NULL)
    {
        _delete_recursive(root->left);
    }
    if(root->right != NULL)
    {
        _delete_recursive(root->right);
    }
    
    free(root);
}
void _print_inorder_recursive(NodePtr root)
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

    _print_inorder_recursive(root->left);
    printf("[ %2.2f ] ", root->value);
    _print_inorder_recursive(root->right);

    printf("\n");
}
NodePtr _inorder_successor_sub(NodePtr node, NodePtr node_parent)
{
    if(node == NULL)
    {
        printf("NULL passed as node argument to _inorder_successor_sub, cannot substitute NULL.");
        return NULL;
    }

    NodePtr successor_parent = node;
    NodePtr successor;

    if(node->left == NULL && node->right != NULL)
    {
        successor = node->right;

        if(node_parent->left->value == node->value)
        {
            node_parent->left = successor;
        }
        else
        {
            node_parent->right = successor;
        }

        free(node);
        return successor;
    }
    else if(node->left != NULL && node->right == NULL)
    {
        successor = node->left;

        if(node_parent->left->value == node->value)
        {
            node_parent->left = successor;
        }
        else
        {
            node_parent->right = successor;
        }

        free(node);
        return successor;
    }
    else if(node->left == NULL && node->right == NULL)
    {
        if(node_parent->left->value == node->value)
        {
            node_parent->left = NULL;
        }
        else
        {
            node_parent->right = NULL;
        }
        
        free(node);
        return NULL;
    }

    successor = node->right;
    NodePtr leaf = successor->left;

    while(1)
    {
        if(leaf != NULL)
        {
            successor_parent = successor;
            successor = leaf;
            leaf = leaf->left;
        }
        else if (successor_parent == node)
        {
            successor->left = node->left;
            break;
        }
        else
        {
            successor_parent->left = successor->right;
            successor->right = node->right;
            successor->left = node->left;
            break;
        }
    }

    if(node_parent == NULL)
    {
        // root of the tree is being deleted, tree->rood will be reassigned in delete_element()
    }
    else if(node_parent->left == node)
    {
        node_parent->left = successor;
    }
    else
    {
        node_parent->right = successor;
    }

    free(node);

    return successor;
}

#pragma endregion

TreePtr create_tree()
{
    TreePtr new = (TreePtr)calloc(1, sizeof(Tree));

    return new;
}
NodePtr search_element(TreePtr tree, double sval)
{
    if(tree == NULL)
    {
        printf("NULL passed to search_element() function.");
    }
    
    NodePtr current = tree->root;

    while (1)
    {
        if(current == NULL)
        {
            printf("Element %2.2lf not found.", sval);
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
    if(tree == NULL)
    {
        return NULL;
    }
    
    NodePtr *parent = &tree->root;
    NodePtr curr = tree->root;

    while(1)
    {
        if(curr == NULL)
        {
            *parent = _create_node(ival);
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
    _delete_recursive((*tree)->root);
    free(*tree);
    *tree = NULL;
}
void delete_subtree(TreePtr* tree, NodePtr ptr)
{
    NodePtr parent = _search_parent(*tree, ptr);

    if(parent == NULL && ptr == (*tree)->root)
    {
        delete_tree(tree);
        return;
    }
    else if(parent == NULL)
    {
        printf("\nNode passed to delete_subtree() does not belong to the tree passed to delete_subtree().\n");
        return;
    }

    _delete_recursive(ptr);

    if(parent->left == ptr)
    {
        parent->left = NULL;
    }
    else
    {
        parent->right = NULL;
    }
}
void delete_element(TreePtr tree, NodePtr node)
{
    NodePtr parent = _search_parent(tree, node);

    if(node == tree->root)
    {
        tree->root = _inorder_successor_sub(node, parent);
    }
    else
    {
        _inorder_successor_sub(node, parent);
    }
}
void print_tree(TreePtr tree)
{
    if(tree == NULL)
    {
        printf("\nNULL passed to print_tree.\n");
        return;
    }
    printf("Tree: \n");
    _print_inorder_recursive(tree->root);
    printf("\n");
};