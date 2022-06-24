#ifndef _DK12_TOOL_H
#define _DK12_TOOL_H

typedef struct tag_node {
	char *value;
	struct tag_node *next;
} Node;

typedef struct tag_list {
	Node *head;
	Node *tail;
} List;


Node *createNode(char *value);
void destroyNode(Node *node);

List *createWordsList(void);
void destroyWordsList(List *list);

void addNodeToWordsList(List *list, char *value);

void sortWords(List *list);
void printWordsList(List *list);


#endif