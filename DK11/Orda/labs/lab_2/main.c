#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(){
    CharListPtr list;
    char s[CB_MAX];

    printf("Введіть слова через пробіл, він розділяє слова, все що не є пробіл буде вважатися словом.\nСпочатку виводиться слово, в скобках кількість символів, довжина слова максимум 35, загальна кількість символів 1024:\n");
    fgets(s, CB_MAX, stdin);

    printf("Список:\n");
    listFill(&list, s);
    displayList(list);

    list = sortList(list);
    printf("Відсортований список:\n");
    displayList(list);

    int count = maxCount(list);
    printf("Найдовщі слова:\n");
    displayMaxList(list, count);

    deleteList(list);
    return 0;
}
