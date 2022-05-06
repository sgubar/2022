#ifndef dk_tool_h
#define dk_tool_h


typedef struct tag_node
{
	int value;
	struct tag_node* next;
	struct tag_node* prev;
} Node;


typedef struct tag_list
{
	int size;
	Node* head;
	Node* tail;
} List;

List* createList();
void deleteList(List* list);

Node* getNode(List* list, int index);

void addElement(List* list, int value);
void delElement(List* list);
void insertElement(List* list, int index, int value);
void replaceElement(List* list, int index, int value);

void printList(List* list);

#endif // !1