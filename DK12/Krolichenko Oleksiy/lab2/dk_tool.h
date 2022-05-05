#ifndef DK_TOOL_H_INCLUDED
#define DK_TOOL_H_INCLUDED

#include <stdbool.h>
#include "List.h"

bool repeatCheck(List* listToSearch, int num);
List* startOfTheList(List* listToSearch, int num);
List* endOfTheList(List* listToSearch, int num);

void reverse(List* startOfTheNode, List* endOfTheNode);
void oddElementsSwap(int index, List* start, List* end);
void evenElementsSwap(int index, List* start, List* end);

#endif