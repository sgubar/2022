#ifndef TOOLS_H
#define TOOLS_H

typedef struct tag_node Node;
struct tag_node {
	int value;
	Node *next;
};

struct tag_list {
	Node *head;
	Node *tail;
};
typedef struct tag_list List;


Node *node_create(int value);
void node_destroy(Node *nd);

List *list_create(void);
void list_destroy(List *ls);

void list_add_node(List *ls, int value);

void list_sort(List *ls);

void list_print(List *ls);

#endif
