#include "dk12_tool.h"
#include <stdlib.h>
//#include <clocale>

static void destroyNode(Node* node);

static Node* createNode(int aValue);

static Node* getSuccessor(BinaryTree* tree, Node* toDelete);

static void printNode(Node* node);

BinaryTree* createTree() {
    BinaryTree* theTree = (BinaryTree*)malloc(sizeof(BinaryTree));

    if (NULL != theTree) {
        theTree->root = NULL;
        theTree->count = 0;
    }

    return theTree;
}

void destroyTree(BinaryTree* tree) {
    if (NULL != tree) {
        destroyNode(tree->root);
        free(tree);
    }
}

void insert(BinaryTree* tree, int aValue) {
    if (NULL == tree) {
        return;
    }

    Node* node = createNode(aValue);
    if (NULL == node) {
        return;
    }

    if (NULL == tree->root) {
        tree->root = node;
        tree->count++;
    }
    else {
        Node* theCurrent = tree->root;
        Node* theParent = NULL;

        while (1) {
            theParent = theCurrent;

            if (aValue < theCurrent->value) {
                theCurrent = theCurrent->left;
                if (NULL == theCurrent) {
                    theParent->left = node;
                    break;
                }
            }
            else {
                theCurrent = theCurrent->right;
                if (NULL == theCurrent) {
                    theParent->right = node;
                    break;
                }
            }
        }

        tree->count++;
    }
}

Node* find(BinaryTree* tree, int aValue) {
    Node* current = NULL;

    if (NULL != tree && NULL != tree->root) {
        current = tree->root;
        while (aValue != current->value) {
            current = (aValue < current->value)
                ? current->left
                : current->right;

            if (NULL == current) {
                break;
            }
        }
    }

    return current;
}

void delete(BinaryTree* tree, int aValue) {

    if (NULL == tree || NULL == tree->root) {
        return;
    }

    Node* current = tree->root;
    Node* parent = tree->root;

    while (aValue != current->value) {
        parent = current;
        if (aValue < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }

        if (NULL == current) {
            return;
        }
    }

    if (NULL == current->left && NULL == current->right) {
        if (tree->root == current) {
            tree->root = NULL;
        }
        else if (parent->left == current) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }

        tree->count--;
    }
    else if (NULL == current->right) {
        if (tree->root == current) {
            tree->root = current->left;
        }
        else if (parent->left == current) {
            parent->left = current->left;
        }
        else {
            parent->right = current->right;
        }
    }
    else if (NULL == current->left) {
        if (tree->root == current) {
            tree->root = current->right;
        }
        else if (parent->right == current) {
            parent->right = current->right;
        }
        else {
            parent->left = current->left;
        }
    }
    else {
        Node* successor = getSuccessor(tree, current);
        if (tree->root == successor) {
            tree->root = NULL;
        }
        else if (parent->left == current) {
            parent->left = successor;
        }
        else {
            parent->right = successor;
        }
        current->left = NULL;
        current->right = NULL;
    }

    destroyNode(current);
}

void print(BinaryTree* tree) {
    if (tree->root == NULL || tree == NULL) {
        //setlocale (LC_CTYPE, "ukr");
        printf("Tree is empty.\n");
        return;
    }
    printf("Values: ");
    printNode(tree->root);
    printf("\n");
}

void printNode(Node* node) {
    if (node == NULL)
        return;

    printNode(node->left);
    printf("%d ", node->value);
    printNode(node->right);
}

void destroyNode(Node* node) {
    if (NULL != node) {
        destroyNode(node->left);
        destroyNode(node->right);

        free(node);
    }
}

Node* createNode(int aValue) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (NULL != node) {
        node->left = NULL;
        node->right = NULL;
        node->value = aValue;
    }

    return node;
}

Node* getSuccessor(BinaryTree* tree, Node* toDelete) {
    Node* successParent = toDelete;
    Node* successor = toDelete;
    Node* current = toDelete->right;

    while (NULL != current) {
        successParent = successor;
        successor = current;
        current = current->left;
    }
    if (successor != toDelete->right) {
        successParent->left = successor->right;
        successor->right = toDelete->right;
    }

    successor->left = toDelete->left;

    return successor;
}