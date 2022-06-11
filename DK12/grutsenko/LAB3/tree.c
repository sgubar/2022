#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

/*
    INT
*/
IntTree *createTree_Int() {
    IntTree *tree = (IntTree*)malloc(sizeof(IntTree));
    if (tree != NULL) {
        tree->root = NULL;
        tree->nodeCount = 0;
    }
    return tree;
}

void destroyTree_Int(IntTree *tree) {
    if (tree != NULL) {
        destroyNode(tree->root);
        free(tree);
    }
}

IntNode *createNodeWithValue_Int(int value) {
   IntNode *node = (IntNode*)malloc(sizeof(IntNode));
   node->data = value;
   node->left = NULL;
   node->right = NULL;
   return node;
}

void destroyNode(IntNode *node) {
    if(NULL != node) {
        destroyNode(node->left);
        destroyNode(node->right);
        free(node);
    }
}

void insertNodeToTree_Int(IntTree *tree, int value) {
    if (NULL == tree) {
        return;
    }
    IntNode *node = createNodeWithValue_Int(value);
    
    if (NULL == node) {
        return;
    }
    if (NULL == tree->root) {
        tree->root = node;
        tree->nodeCount ++;
    } else {
        IntNode *current = tree->root;
        IntNode *parent = NULL;

        while(1) {
            parent = current;
            if(value < current->data) {
                current = current->left;
                if(NULL == current) {
                    parent->left = node;
                    break;
                }

            } else {
                current = parent->right;
                if(NULL == current) {
                    parent->right = node;
                    break;
                }
            }
        }
        tree->nodeCount ++;
    }
}

IntNode *findNodeByValue_Int(IntTree *tree, int value) {
        IntNode *current = NULL;
        if (NULL != tree && NULL != tree->root) {
            current = tree->root;

            while(value != current->data) {
                if(value < current->data) {
                    current = current->left;
                } else { 
                    current = current->right;
                }
                if(NULL == current) {
                    break;
                }
            }       
        }
        return current;
}
       
void deleteNodeByValue_Int(IntTree *tree, int value) {
    if (NULL == tree || NULL == tree->root) {
        return;
    }

    IntNode *current = tree->root;
    IntNode *parent = tree->root;

    /*
    Find function
    */
    while(value != current->data) {
        parent = current;
        if(value < current->data) {
            current = current->left;
        } else { 
            current = current->right;
        }
        if(NULL == current) {
            return;
        }
    }  

    /*
    current = node to delete

        current is leaf
    */
    if(NULL == current->left && NULL == current->right) {
        if(tree->root == current) {
            tree->root = NULL;
        }
        else if(parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        tree->nodeCount --;

    /*
        current has only left child
    */
    } else if(NULL == current->right) {
        if(tree->root == current) {
            tree->root = current->left;
        } else if(parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
    /*
        current has only right child
    */
    } else if(NULL == current->left) {
        if(tree->root == current) {
            tree->root = current->right;
        } else if(parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }

    /*
        current has both successors
    */
    } else {
        IntNode *successor = getSuccessor(tree, current);
        if (tree->root == successor) {
            tree->root = NULL;
        } else if(parent->left == current) {
            parent->left = successor;
        } else {
            parent->right = successor;
        }
    }

}

IntNode *getSuccessor(IntTree *tree, IntNode *nodeToDelete) {
    IntNode *successorParent = nodeToDelete;
    IntNode *successor = nodeToDelete;
    IntNode *current = nodeToDelete->right;
    
    while (NULL != current) {
        successorParent = successor;
        successor = current;
        current = current->left;
    }
    if(successor != nodeToDelete->right) {
        successorParent->left = successor->right;
        successor->right = nodeToDelete->right;
    }
    return successor;
}

void printNode_Int(IntNode *node) {
    if (node == NULL) {
        return;
    }
    printNode_Int(node->left);
    printNode_Int(node->right);
    printf("%d\n", node->data);
}

/*
Прямий обхід 
 */
void printTree_Int(IntNode *root) {
    if (root == NULL) {
        return;
    }    
    printf("%d\n", root->data);

    printTree_Int(root->left);
    printTree_Int(root->right);
}