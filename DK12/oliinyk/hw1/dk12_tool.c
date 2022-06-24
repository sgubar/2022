#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dk12_tool.h"

int getBinaryNumber(void) {
    char numberChar;
    char numberArray[256];
    int count = 0;
    printf("Type binary number\n");
    while(scanf("%c", &numberChar)==1) {
        if (numberChar != '0' && numberChar != '1') {
            if (numberChar == '\n') break;
            printf("Only binary number!");
            exit(0);
        }
        numberArray[count] = numberChar;
        count++;
        if (count > 8) {
            printf("Max 8 numbers!");
            exit(0);
        }
    }
    const char *pNumberArray = &numberArray;
    int number = atoi(pNumberArray);
    return number;
}


int binaryToInt(int number) {
    char numberArray[256];
    sprintf(numberArray, "%d", number);
    int result = 0;
    int i = 0;
    int count = strlen(numberArray);
    while (count != 0)
    {
        result = result * 2 + (numberArray[i] - '0');
        i++;
        count--;
    }
    return result;
}

void printResult(int result) {
    printf("Result: %i\n", result);
}