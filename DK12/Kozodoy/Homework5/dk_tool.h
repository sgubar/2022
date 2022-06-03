#ifndef dk_tool_h
#define dk_tool_h


typedef struct tag_node
{
	int value;
	struct tag_node* left;
	struct tag_node* right;
	struct tag_node* parent;
} Node;

typedef struct tag_tree
{
	int size;
	Node* root;
} Tree;

Tree* createTree();

void deleteNode(Node* node);
void deleteTree(Tree* tree);

void addElement(Tree* tree, int value);
Node* getElement(Tree* tree, int value);
void delElementByValue(Tree* tree, int value);

void printElement(Node* node);
void printTree(Tree* tree);

#endif // !1