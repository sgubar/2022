#define _CRT_SECURE_NO_WARNINGS
#ifndef DK12_TOOL_H_INCLUDED
#define DK12_TOOL_H_INCLUDED
#include <stdio.h>

int random();
extern const int kSLListError;
typedef struct __CharNode CharNode;

struct __CharNode {
	char value;
	CharNode* nextNode;
};

typedef struct __CharNode CharNode;

typedef struct __CharList {
	CharNode* head;
	CharNode* tail;
	int count;
} CharList;

CharNode* SLCreateNodeCharValue(char aValue);
void SLFreeCharNode(CharNode* aNode);
void SLAddNode(CharList* aList, CharNode* aNewNode);
void SLInsertNodeIndex(CharList* alist, CharNode* value, int index);
void SLRemovedNodeIndex(CharList* aList, int anIndex);
CharNode* SLNodeIndex(const CharList* aList, int aIndex);
CharList* SLCreateList();
void SLFreeList(CharList* aList);
int SLCountList(const CharList* aList);
void doPrintSLList(const CharList* aList);
void doPrintSLListConversely(const CharList* aList);
void SLSwapNodesByIndex(CharList* aList, int theLeft, int theRight);
int partitionIt(CharList* aList, int aLeftIndex, int aRightIndex);
#endif
