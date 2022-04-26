#include "dbllist.h"
#include <stdlib.h>

Node *createDblListIntElement(int value){
    Node *result = (Node *)malloc(sizeof(Node));
    if(result != NULL){
        result->value = value;
        result->next = NULL;
        result->prev = NULL;
    }
    return result;
}

void deleteDblListIntElement(Node *element){
    if (element != NULL) {
		free(element);
	}
}

void printDblListIntElement(Node *element){
	if (element != NULL) {
		printf("%d", element->value);
	}
}

IntDblList *createIntDblList(void){
    IntDblList *result = (IntDblList *)malloc(sizeof(IntDblList));

    if (result != NULL){
    result->head = NULL;
    result->tail = NULL;
    }
    return result;
}

void deleteIntDblList(IntDblList *list){
    if (list == NULL){
    return;
    }
    Node *element = list->head;
    Node *element2 = list->tail;

    while (element != NULL){
    Node *temp = element->next;
    deleteDblListIntElement(element);
    element = temp;
    }
    while (element2 != NULL){
    Node *temp = element2->prev;
    deleteDblListIntElement(element2);
    element2 = temp;
    }
    free(list);
}

void printIntDblListFromHead(IntDblList *list){
    if (list == NULL){
        printf("Invalid a pointer to the list\n");
        return;
    }
    printf("Printing double list... Please Wait\n\n");
    printf("[");
    for (Node *element = list->head; element != NULL; element = element->next){
    printDblListIntElement(element);
    if (element->next != NULL){
    printf(",");
   }
   }
    printf("]\n");
}

long countOfIntSingleList(IntDblList *list){
    if (NULL == list){
        return 0;
    }
    long count = 0;
    Node *element = list->head;

    while(element != NULL){
        element = element->next;
        count++;
   }
   
    return count;
}

int addIntValueToIntDblList(IntDblList *list, int value){
    if (list == NULL){
        return 0;
    }
    Node *element = createDblListIntElement(value);
    if (element == NULL){
        return 0;
    }
    if (list->head == NULL){
        list->head = element;
        return 1;
    }
    Node *tail = list->head;

    while(NULL != tail->next){
    tail = tail->next;
    }
    tail->next = element;
    return 1;
}
void removeLastElementFromIntDblList(IntDblList *list){
    if (list == NULL){
        return;
    }
    if (list->head == NULL){
        return;
    }
    Node *element = list->head;

    if (element->next == NULL){
        list->head = NULL;
        deleteDblListIntElement(element);
        return;
     }

    while(element->next != NULL && element->next->next != NULL){
    element = element->next;
    }
    deleteDblListIntElement(element->next);
    element->next = NULL;
}
void removeFirstElementFromIntDblList(IntDblList *list){
    if (list == NULL){
        return;
    }
    if (list->head == NULL){
        return;
    }
    Node *element = list->head->next;
    deleteDblListIntElement(list->head);
    list->head = element;
}


int insertIntElementToIntDblListAtIndex(IntDblList *list, int index, int value){
    if (list == NULL){
    return 0;
    }
    long count = countOfIntSingleList(list);

    if (count == index){
       return addIntValueToIntDblList(list, value);
    }
    Node *element = createDblListIntElement(value);
    if (element == NULL){
        return 0;
    }
    if (index == 0){
        element->next = list->head;
        list->head = element;
    } else{
        int current = 0;
        Node *prev_element = list->head;
        while(prev_element != NULL && current < index - 1){
            prev_element = prev_element->next;
            current++;
        }

        element->next = prev_element->next;
        prev_element->next = element;

    }
    return 1;
}

int removeIntElementFromIntDblListAtIndex(IntDblList *list, int index){
    if (list == NULL){
        return 0;
    }
    long count = countOfIntSingleList(list);
    if (index >= count){
        return 0;
    }
    if (index == 0){
        removeFirstElementFromIntDblList(list);
        return 1;
    }else if(index == count - 1){
        removeLastElementFromIntDblList(list);
        return 1;
    }else{
        int current = 0;
        Node *prev_element = list->head; 
        while(prev_element != NULL && current < index - 1){
        Node *temp = prev_element->next;
        prev_element->next = temp->next;
        prev_element = prev_element->next;
        current++;
        deleteDblListIntElement(temp);
    }
    }
    return 1;
}
