#ifndef LIST_H
#define LIST_H

struct node {
	int value;
	struct node *next;
};
typedef struct node* Node;

struct list {
	struct node *head;
	struct node *tail;
};
typedef struct list* List;

/* -------------------------------------------- */

Node node_create(int value);
void node_destroy(Node nd);

List list_create(void);
void list_destroy(List ls);

void list_add_node(List ls, int value);
void list_add_node_tail(List ls, int value);
void list_add_node_head(List ls, int value);

void list_sort_ascend(List ls);
void list_sort_descend(List ls);

void list_print(List ls);

#endif // LIST_H
