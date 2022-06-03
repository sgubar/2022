#include <stdlib.h>

#include "list.h"

ListElement *createListElement(float value){
    ListElement *result = (ListElement *)malloc(sizeof(ListElement));

    if (NULL != result){
        result->value = value;
        result->next = NULL;
    }

    return result;
}

void deletListElement(ListElement *element){
    if(NULL != element){
        free(element);
    }
}

void printListElement(ListElement *element){
    if(NULL != element){
        printf("%0.2f", element->value);
    }
}

SingleList *createSingleList(void){
    SingleList *result = (SingleList *)malloc(sizeof(SingleList));

    if(NULL != result){
        result->head = NULL;
    }

    return result;
}

void deletSingleList(SingleList *list){
    if(NULL == list){
        return ;
    }

    ListElement *element = list->head;

    while(NULL != element){
        ListElement *tmp = element->next;
        deletListElement(element);
        element = tmp;
    }

    free(list);
}

void printSingleList(SingleList *list){
    if (NULL == list){
        printf("Invalid a pointer to the list\n");
        return ;
    }

    printf("[");

    for (ListElement *element = list->head; element != NULL; element = element->next) {
		printListElement(element);
		if(element->next != NULL){
            printf(", ");
		}

	}

    printf("]\n");
}

long countOfSingleList(SingleList *list){
    if(NULL == list){
        return NULL;
    }

    long count = 0;

    for (ListElement *element = list->head; element != NULL; element = element->next, count++);

    return count;
}

int addFloatValueToSingleList(SingleList *list, float value){
    if (NULL == list){
        return 0;
    }

    ListElement *element = createListElement(value);
    if (NULL == element){
        return 0;
    }

    if(NULL == list->head){
        list->head = element;
        return 1;
    }

    ListElement *tail = list->head;

    while(NULL != tail->next){
        tail = tail->next;
    }

    tail->next = element;

    return 1;
}

void removeLastElementFromSingleList(SingleList *list){
    if(NULL == list){
        return;
    }

    if(NULL == list->head){
        return;
    }

    ListElement *element = list->head;

    if(NULL == element->next){
        list->head = NULL;
        deletListElement(element);
        return;
    }

    while(NULL != element->next && NULL != element->next->next){
        element = element->next;
    }
    deletListElement(element->next);
    element->next = NULL;
}

void removeFirsElementFromSingleList(SingleList *list){
    if(NULL == list){
        return 0;
    }

    if(NULL == list->head){
        return;
    }

    ListElement *element = list->head->next;
    deletListElement(list->head);
    list->head = element;
}

int insertFloatElementToSingleListByIndex(SingleList *list, float value, int index){
    if(NULL == list){
        return 0;
    }

    long count = countOfSingleList(list);

    if(count == index){
        return addFloatValueToSingleList(list, value);
    }

    ListElement *element = createListElement(value);

    if(NULL == element){
        return 0;
    }

    if(0 == index){
        element->next = list->head;
        list->head = element;
    }else{
        int current = 0;
        ListElement *ex_element = list->head;
        for (;ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++);

        element->next = ex_element->next;
        ex_element->next = element;
    }

    return 1;
}

int removetFloatElementToSingleListByIndex(SingleList *list, int index){
    if (NULL == list){
        return 0;
    }

    long count = countOfSingleList(list);

    if (index >= count){
        return 0;
    }

    if (0 == index){
        removeFirsElementFromSingleList(list);
        return 1;
    }else if (index == (count - 1)){
        removeLastElementFromSingleList(list);
        return 1;
    }else{
    int current = 0;
    ListElement *ex_element = list->head;
    for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++){
        ListElement *to_delet = ex_element->next;
        ex_element->next = to_delet->next;
        deletListElement(to_delet);
    }
    }
    return 1;
}
