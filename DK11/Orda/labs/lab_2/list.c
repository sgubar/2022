#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "list.h"

void listFill(CharListPtr* list, char* s){
    size_t n;
    CharListPtr current, head, temporary;
    const char delim[] = " \t\n";

    head = temporary = NULL;
    for(s = strtok(s, delim); s != NULL; s = strtok(NULL, delim)){

        if((current = (CharListPtr)malloc(sizeof(CharList))) == NULL){
            break;
        }else{
            current->next = NULL;
        }

        if((n = strlen(s)) >= WORD_LEN){
            n = WORD_LEN - 1;
        }

        strncpy(current->w, s, n);
        current->w[n] = '\0';

        if(head == NULL){
            head = temporary = current;
        }
        else{
            temporary = temporary->next = current;
        }

        current->count = strlen(current->w);
    }
    *list = head;
}

void deleteList(CharListPtr list){
    CharListPtr temporary;
    while(list != NULL){
        temporary = list;
        list = list->next;
        free(temporary);
    }
}

void displayList(CharListPtr list){
    if(list == NULL){
        printf("Список відсутній\n");
    }else{
        printf("[");
        for(CharListPtr current = list; current != NULL; current = current->next){
            printf("%s(%d)", current->w, current->count);
            if(current->next != NULL){
                printf(", ");
            }
        }
        printf("]\n");
    }
}

CharListPtr sortList(CharListPtr list){
    if(list == NULL){
        return;
    }

    CharListPtr newList = NULL;

    while (list != NULL)
    {
        CharListPtr node = list;
        list = list->next;

        if (newList == NULL || node->count < newList->count)
        {
            node->next = newList;
            newList = node;
        }
        else
        {
            CharListPtr current = newList;
            while (current->next != NULL && !(node->count < current->next->count))
            {
                  current = current->next;
            }

            node->next = current->next;
            current->next = node;
        }
    }

    return newList;
}

int maxCount(CharListPtr list){
    int maxCount;
    for(CharListPtr current = list; current != NULL; current = current->next){
        maxCount = current->count;
    }

    return maxCount;
}

void displayMaxList(CharListPtr list, int countm){
    if(list == NULL){
        printf("Список відсутній\n");
    }else{
        printf("[");
        for(CharListPtr current = list; current != NULL; current = current->next){
            if(current->count == countm){
                printf("%s(%d)", current->w, current->count);
                if(current->next != NULL){
                    printf(", ");
                }
            }
        }
        printf("]\n");
    }
}
