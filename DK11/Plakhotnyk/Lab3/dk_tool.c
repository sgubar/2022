#include <stdlib.h>
#include "dk_tool.h"

static void deleteNode(Node *node);
static Node *createNodeWithValue(int value);

Tree *createTree()
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));

    if (tree != NULL)
    {
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

void deleteTree(Tree *tree)
{
    deleteNode(tree->root);
    free(tree);
}

static void deleteNode(Node *node)
{
    if (NULL != node)
    {
        deleteNode(node->leftChild);
        deleteNode(node->rightChild);
        free(node);
    }
}

static Node *createNodeWithValue(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (NULL != node)
    {
        node->leftChild = NULL;
        node->rightChild = NULL;
        node->value = value;
    }
    return node;
}

void insertValueToTree(Tree *tree, int value)
{
    if (NULL == tree)
        return;

    Node *theNode = createNodeWithValue(value);
    if (NULL == theNode)
        return;

    if (NULL == tree->root)
        tree->root = theNode;

    else
    {
        Node *theCurrent = tree->root;
        Node *theParent = NULL;

        while (1)
        {
            theParent = theCurrent;

            if (value < theCurrent->value)
            {
                theCurrent = theCurrent->leftChild;
                if (NULL == theCurrent)
                {
                    theParent->leftChild = theNode;
                    break;
                }
            }
            else
            {
                theCurrent = theCurrent->rightChild;
                if (NULL == theCurrent)
                {
                    theParent->rightChild = theNode;
                    break;
                }
            }
        }
    }
    tree->count++;
}

Node *findNodeWithValue(Tree *tree, int value)
{
    Node *theCurrentNode = NULL;

    if (NULL != tree)
    {
        theCurrentNode = tree->root;
        while (value != theCurrentNode->value)
        {
            theCurrentNode = (value < theCurrentNode->value)
                                 ? theCurrentNode->leftChild
                                 : theCurrentNode->rightChild;

            if (NULL == theCurrentNode)
            {
                printf("\n\nnode does not exist!!!\n\n");
                break;
            }
        }
    }
    return theCurrentNode;
}

Node *getRecipient(Tree *tree, Node *delNode)
{
    Node *theRecipientParent = delNode;
    Node *theRecipient = delNode;
    Node *theCurrent = delNode->rightChild;

    while (NULL != theCurrent)
    {
        theRecipientParent = theRecipient;
        theRecipient = theCurrent;
        theCurrent = theCurrent->leftChild;
    }

    if (theRecipient != delNode->rightChild)
    {
        theRecipientParent->leftChild = theRecipient->rightChild;
        theRecipient->rightChild = delNode->rightChild;
    }
    return theRecipient;
}

int deleteValueFromTree(Tree *tree, int value)
{
    int theResult = 1;
    Node *theCurrent = tree->root;
    Node *theParent = tree->root;
    int LeftChild = 1;

    while (value != theCurrent->value)
    {
        theParent = theCurrent;
        if (value < theCurrent->value)
        {
            LeftChild = 1;
            theCurrent = theCurrent->leftChild;
        }
        else
        {
            LeftChild = 0;
            theCurrent = theCurrent->rightChild;
        }

        if (NULL == theCurrent)
            return 0;
    }

    if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
    {
        if (tree->root == theCurrent)
            tree->root = NULL;

        else if (LeftChild)
            theParent->leftChild = NULL;

        else
            theParent->rightChild = NULL;
    }
    else if (NULL == theCurrent->rightChild)
    {
        if (tree->root == theCurrent)
            tree->root = theCurrent->leftChild;

        else if (LeftChild)
            theParent->leftChild = theCurrent->leftChild;

        else
            theParent->rightChild = theCurrent->leftChild;
    }
    else if (NULL == theCurrent->leftChild)
    {
        if (tree->root == theCurrent)
            tree->root = theCurrent->rightChild;

        else if (LeftChild)
            theParent->leftChild = theCurrent->rightChild;

        else
            theParent->rightChild = theCurrent->rightChild;
    }
    else
    {
        Node *theRecipient = getRecipient(tree, theCurrent);
        if (tree->root == theRecipient)
            tree->root = NULL;

        else if (LeftChild)
            theParent->leftChild = theRecipient;

        else
            theParent->rightChild = theRecipient;
    }

    free(theCurrent);
    theResult = 1;
    return theResult;
}

void printTree(Node *root)
{
    if (NULL == root)
        return;
    printf("%d ", root->value);
    printTree(root->leftChild);
    printTree(root->rightChild);
}
