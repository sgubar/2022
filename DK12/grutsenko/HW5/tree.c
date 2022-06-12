#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

FloatTree *createTree_Float() {
    FloatTree *tree = (FloatTree*)malloc(sizeof(FloatTree));
    if (tree != NULL) {
        tree->root = NULL;
        tree->nodeCount = 0;
    }
    return tree;
}

void destroyTree_Float(FloatTree *tree) {
    if (tree != NULL) {
        destroyNode(tree->root);
        free(tree);
    }
}

FloatNode *createNodeWithValue_Float(float value) {
   FloatNode *node = (FloatNode*)malloc(sizeof(FloatNode));
   node->data = value;
   node->left = NULL;
   node->right = NULL;
   return node;
}

void destroyNode(FloatNode *node) {
    if(NULL != node) {
        destroyNode(node->left);
        destroyNode(node->right);
        free(node);
    }
}

void insertNodeToTree_Float(FloatTree *tree, float value) {
    if (NULL == tree) {
        return;
    }
    FloatNode *node = createNodeWithValue_Float(value);
    
    if (NULL == node) {
        return;
    }
    if (NULL == tree->root) {
        tree->root = node;
        tree->nodeCount ++;
    } else {
        FloatNode *current = tree->root;
        FloatNode *parent = NULL;

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

FloatNode *findNodeByValue_Float(FloatTree *tree, float value) {
        FloatNode *current = NULL;
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
       
void deleteNodeByValue_Float(FloatTree *tree, float value) {
    if (NULL == tree || NULL == tree->root) {
        return;
    }

    FloatNode *current = tree->root;
    FloatNode *parent = tree->root;

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
        FloatNode *successor = getSuccessor(tree, current);
        if (tree->root == successor) {
            tree->root = NULL;
        } else if(parent->left == current) {
            parent->left = successor;
        } else {
            parent->right = successor;
        }
    }

}

FloatNode *getSuccessor(FloatTree *tree, FloatNode *nodeToDelete) {
    FloatNode *successorParent = nodeToDelete;
    FloatNode *successor = nodeToDelete;
    FloatNode *current = nodeToDelete->right;
    
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

void printNode_Float(FloatNode *node) {
    if (node == NULL) {
        return;
    }
    printNode_Float(node->left);
    printNode_Float(node->right);
    printf("%f\n", node->data);
}

/*
Прямий обхід 
 */
void printTree_Float(FloatNode *root) {
    if (root == NULL) {
        return;
    }    
    printf("%f\n", root->data);

    printTree_Float(root->left);
    printTree_Float(root->right);
}