#ifndef dk_tool_h
#define dk_tool_h


typedef struct tag_node
{
	float value;
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

void addElement(Tree* tree, float value);
void inputElement(Tree* tree);

Node* getElement(Tree* tree, float value);
void delElementByValue(Tree* tree, float value);
void delElement(Tree* tree);

void printElement(Node* node);
void printTree(Tree* tree);

#endif // !1