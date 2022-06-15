#include <stdlib.h>
#include <stdio.h>


typedef struct TreeNode Node, *NodePtr;
typedef struct Tree Tree, *TreePtr;

struct TreeNode
{
    double value;
    NodePtr left;
    NodePtr right;
};
struct Tree
{
    NodePtr root;
};

TreePtr create_tree();
NodePtr search_element(TreePtr, double);
NodePtr insert_element(TreePtr, double);
void delete_subtree(NodePtr*);
void delete_tree(TreePtr*);
void delete_element(TreePtr, NodePtr);
void print_tree(TreePtr);