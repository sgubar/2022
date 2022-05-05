#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

#include "List.h"
#include "dk_tool.h"
    
void oddElementsSwap(int index, List* start, List* end) {
    
    index--;
    while (index > 0) {
        List* iter = start;

        for (int i = 0; i < index; i++) {
            iter = iter->next;
        }

        end = iter;
        swapNodes(start, iter);
        start = start->next;
        index -= 2;
    }
}

void evenElementsSwap(int index, List* start, List* end) {
    index--;
    while (index >= 2) {
        List* iter = start;

        for (int i = 0; i < index; i++) {
            iter = iter->next;
        }

        end = iter;
        swapNodes(start, iter);
        start = start->next;
        index -= 2;
    }
}

bool repeatCheck(List* listToSearch, int num) {

    int occurrences = 0;
    List* iter = listToSearch;

    while (iter != NULL) {
        if (iter->val == num)
            occurrences++;
        iter = iter->next;
    }

    return (occurrences >= 2);
}

List* startOfTheList(List* listToSearch, int num) {
    List* iter = listToSearch;

    while (iter != NULL) {
        if (iter->val == num)
            return iter;
        iter = iter->next;
    }
}
List* endOfTheList(List* listToSearch, int num)
{
    bool meet = false;
    List* iter = listToSearch;
    List* valueToReturn = 0;

    while (iter != NULL) {
        if (iter->val == num)
            valueToReturn = iter;
        iter = iter->next;
    }
    return valueToReturn;
}

void reverse(List* startNode, List* endNode) {
    int index = 0;
    List* iter = startNode;

    while (iter != endNode) {
        index++;
        iter = iter->next;
    }
    index--;

    if (!(index % 2)) {
        oddElementsSwap(index, startNode->next, endNode);
    }

    else
        if (index % 2) {
            evenElementsSwap(index, startNode->next, endNode);
        }
}
