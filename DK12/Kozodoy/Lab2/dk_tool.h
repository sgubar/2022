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

int avgList(List* list);

void addElement(List* list, int value);
void inputElement(List* list);
void delAvgElement(List* list);

void printList(List* list);

#endif // !1