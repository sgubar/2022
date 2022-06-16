#include "charList.h"

ElementPtr get_nth(ListPtr list, int index)
{
    if(list == NULL || index < 0)
    {
        return NULL;
    }

    ElementPtr curr = list->first;

    for (int i = 0; i < index; i++)
    {
        if(curr == NULL)
        {
            break;
        }
        curr = curr->next;
    }
    
    return curr;
}
ListPtr init_list(char* elements)
{
    int len = strlen(elements);
    ListPtr list = calloc(1, sizeof(List));
    ElementPtr curr = calloc(1, sizeof(Element));

    if(list == NULL || curr == NULL || len < 1)
    {
        free(list);
        free(curr); 
        return NULL;
    }

    list->first = curr;
    list->length = len;
    curr->prev = NULL;
    curr->value = elements[0];

    for (int i = 1; i < len; i++)
    {
        ElementPtr e = calloc(1, sizeof(Element));
        e->value = elements[i];
        e->prev = curr;
        curr->next = e;
        curr = e;
    }

    curr->next = NULL;
    list->last = curr;

    return list;
};
void free_list(ListPtr list)
{
    if(list == NULL)
    {
        return;
    }

    ElementPtr curr = list->first;

    while(curr != NULL)
    {
        ElementPtr next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);
};
int delete_nth(ListPtr list, int index)
{
    ElementPtr nth = get_nth(list, index);

    if(nth == NULL)
    {
        printf("\ndelete_nth has failed: index out of range.\n");
        return 0;
    }

    if(nth->prev == NULL)
    {
        list->first = nth->next;
    }
    else
    {
        nth->prev->next = nth->next;
    }
    if(nth->next == NULL)
    {
        list->last = nth->prev;
    }
    else
    {
        nth->next->prev = nth->prev;
    }

    --(list->length);

    free(nth);

    return 1;
};
// this function sews two lists at a given joint element, thus src->first becomes [dest_index]`th element of dest list,
// while the rest of dest (meaning elements starting with the original [dest_index]`th element) gets appended to the end of resulting list
int merge_lists(ListPtr src, ListPtr dest, int dest_index)
{
    if(src == NULL)
    {
        printf("Invalid src list passed to merge_lists.\n");
        return 0;
    }

    ElementPtr prev = get_nth(dest, dest_index - 1);
    ElementPtr joint = get_nth(dest, dest_index);

    if(joint == NULL && prev == NULL)
    {
        printf("Invalid destination list or an out of range index passed to merge_lists.\n");
        return 0;
    }
    
    src->first->prev = prev;

    if(prev != NULL)
    {
        prev->next = src->first;
    }
    else
    {
        dest->first = src->first;
    }

    src->last->next = joint;

    if(joint != NULL)
    {
        joint->prev = src->last;
    }
    else
    {
        dest->last = src->last;
    }

    dest->length += src->length;

    free(src);
    return 1;
};
int insert_elements(ListPtr list, char* elements, int index)
{
    ListPtr new = init_list(elements);

    merge_lists(new, list, index);
};
int append_elements(ListPtr list, char* elements)
{
    insert_elements(list, elements, list->length);
};
int duplicate_element(ListPtr list, char* element)
{
    if(list == NULL)
    {
        printf("duplicate_element has failed.");
        return 0;
    }

    int len = list->length;

    for (int i = 0; i < len; i++)
    {
        ElementPtr curr = get_nth(list, i);
        
        if(curr->value == *element)
        {
            insert_elements(list, element, i);
            len++;
            i++;
        }
    }
    
    return 1;
};
void print_list(ListPtr list)
{
    if(list == NULL)
    {
        printf("\n[NULL]\n\n");
    }

    ElementPtr curr = list->first;

    printf("\n");

    for (int i = 0; i < index; i++)
    {
        if(curr == NULL)
        {
            break;
        }

        if((i) % 4 == 0)
        {
            printf("%2i - %2i: ", i, i + 3);
        }

        printf("[(%c) %c (%c)]  ", curr->prev == NULL ? ' ' : curr->prev->value, curr->value, curr->next == NULL ? ' ' : curr->next->value);

        if((i + 1) % 4 == 0)
        {
            printf("\n");
        }

        curr = curr->next;
    }
    printf("\nLength: %i", list->length);
    printf("\n\n");
};