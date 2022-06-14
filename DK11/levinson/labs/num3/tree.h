#include <stdlib.h>


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
void delete_subtree(NodePtr*);
void delete_tree(TreePtr*);
NodePtr get_element(TreePtr, double);
NodePtr insert_element(TreePtr, double);
void delete_element(TreePtr, double);
void print_tree(TreePtr);