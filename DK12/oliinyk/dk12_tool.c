#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dk12_tool.h"


void checkBinaryNumber(void) {
    char number;
    printf("Type binary number\n");
    while(scanf("%c", &number)==1) {
        if (number != '0' && number != '1') {
            if (number == '\n') break;
            printf("Only binary number!");
            exit(0);
        }
        numberArray[count] = number;
        count++;
    }
}

void binaryToInt(void) {
    int i = 0;
    while (count != 0)
    {
        result = result * 2 + (numberArray[i] - '0');
        i++;
        count--;
    }
}

void printResult(void) {
    printf("Result: %i\n", result);
}