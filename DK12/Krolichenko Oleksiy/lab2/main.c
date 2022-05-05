#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

#include "dk_tool.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int listSize;
    List* myList = input(&listSize);

    int setElement;
    printf("Задайте елемент: ");
    scanf("%d", &setElement);

    if (repeatCheck(myList, setElement)) {
        printf("Зворотній порядок: ");

        List* start = startOfTheList(myList, setElement);
        List* end = endOfTheList(myList, setElement);

        reverse(start, end);
    }
    else {
        printf("Двох однакових елементів не знайдено\n");
    }

    printList(myList);
    destroyList(myList);

    return 0;
}   