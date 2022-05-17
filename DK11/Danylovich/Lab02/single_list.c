#include "single_list.h"
#include <stdlib.h>
#include <cs50.h>

Node *createSingleListIntElement(int value){
	Node *result = (Node *)malloc(sizeof(Node));

	if(result != NULL){
		result->value = value;
		result->next = NULL;
	}

	return result;
}

void deleteSingleListIntElement(Node *element){
	if(element != NULL){
		free(element);
	}
}

IntSingleList *getIntElementToIntSingleList(){
    int a=1,i=1;
    printf("Створення списку...\n");
    IntSingleList *b = createIntSingleList();
    if(b != NULL){
    while(a!=0){
    printf("Задайте інтеджер для %i елементу списку(Якщо хочете закінчити введення введіть цифру 0 або будь-яку букву): ",i);
    scanf("%d", &a);
    addIntValueToIntSingleList(b,a);
    i++;
    }
    }
removeLastElementFromIntSingleList(b);
return b;
}

void printSingleListIntElement(Node *element){
	if(element != NULL){
		printf("%d", element->value);
	}
}

IntSingleList *createIntSingleList(void){
	IntSingleList *result = (IntSingleList *)malloc(sizeof(IntSingleList));

	if(result != NULL){
		result->head = NULL;
	}

	return result;
}

void deleteIntSingleList(IntSingleList *list){
	if(list == NULL){
		return;
	}

	Node *element = list->head;

	while(element != NULL){
		Node *temp = element->next;
		deleteSingleListIntElement(element);
		element = temp;
	}
	free(list);
}

void printIntSingleList(IntSingleList *list){

	if(list == NULL){
		printf("Invalid a pointer to the list\n");
		return;
	}
	printf("[");
	for (Node *element = list->head; element != NULL; element = element->next){
		printSingleListIntElement(element);
		if (element->next != NULL){
			printf(",");
		}
	}

	printf("]\n");
}

int MNOfIntSingleList(IntSingleList *list){
	if(list == NULL){
 		return 0;
	}

	int count = 0;
    int sum = 0;
    Node *element = list->head;
    while(element != NULL){
        sum += element->value;
        element = element->next;
        count++;
    }
    if(count != 0){
    printf("Знаходження середнього арифметичного списку...\n\n");
    printf("Середнє арифметичне: %i\n\n",sum/count);
    return sum/count;
    }else return -1;
}

long countOfIntSingleList(IntSingleList *list){
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

int addIntValueToIntSingleList(IntSingleList *list, int value){
	if(list == NULL){
 		return 0;
	}

	Node *element = createSingleListIntElement(value);
	if(element == NULL){
		return 0;
	}

	if(list->head == NULL){
		list->head = element;
		return 1;
	}

	Node *tail = list->head;

	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

void removeLastElementFromIntSingleList(IntSingleList *list){
	if(list == NULL){
 		return;
	}

	if(list->head == NULL){
		return;
	}

	Node *element = list->head;

	if(element->next == NULL){
		list->head = NULL;
		deleteSingleListIntElement(element);
		return;
	}

	while(element->next != NULL && element->next->next != NULL){
		element = element->next;
	}
	deleteSingleListIntElement(element->next);
	element->next = NULL;
}

void removeFirstElementFromIntSingleList(IntSingleList *list){
	if(list == NULL){
 		return;
	}

	if(list->head == NULL){
		return;
	}
    printf("Видалення першого числа списку...\n\n");
	Node *element = list->head->next;
	deleteSingleListIntElement(list->head);
	list->head = element;
}

int removeIntElementsWhichLessThenMN(IntSingleList *list, int MNumber){
    if(list == NULL){
 		return 0;
	}

	if(list->head == NULL){
		return 0;
	}
    Node *element = list->head;
    printf("Видалення числа менше за середнє...\n\n");
    while(element != NULL && element->value < MNumber){
        Node *temp = element->next;
        element->next = temp->next;
        element = element->next;
        free(temp);
    }
return 1;
}

int insertIntElementToIntSingleListAtIndex(IntSingleList *list, int index, int value){
	if(list == NULL){
 		return 0;
	}

	long count = countOfIntSingleList(list);

	if(count == index){
		return addIntValueToIntSingleList(list, value);
	}

	Node *element = createSingleListIntElement(value);
	if(element == NULL){
		return 0;
	}

	if(index == 0){
		element->next = list->head;
		list->head = element;
	} else {
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

int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index){
	if(NULL == list){
 		return 0;
	}

	long count = countOfIntSingleList(list);
	if(index >= count){
		return 0;
	}

	if(0 == index){
		removeFirstElementFromIntSingleList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromIntSingleList(list);
		return 1;
	} else {
		int current = 0;
		Node *prev_element = list->head; 
        while(prev_element != NULL && current < index - 1){
        Node *temp = prev_element->next;
        prev_element->next = temp->next;
        prev_element = prev_element->next;
        current++;
        deleteSingleListIntElement(temp);
    }
    }
    return 1;
}
