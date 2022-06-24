#include <stdlib.h>
#include <stdio.h>
#include "dk_tool.h"

int processingBinaryNumber(void)
{
    char numberArray[8];
    int count = 0;
    char number;
    printf("Введіть двікове число\n");
    while (scanf("%c", &number) == 1)
    {
        if (number != '0' && number != '1')
        {
            if (number == '\n')
                break;
            printf("Тільки число двійкової системи!");
            exit(0);
        }
        numberArray[count] = number;
        count++;
        if (count > 8)
        {
            printf("Максимум 8 цифр!");
            exit(0);
        }
    }

    int result = 0;
    int i = 0;
    while (count != 0)
    {
        result = result * 2 + (numberArray[i] - '0');
        i++;
        count--;
    }
    return result;
}

void printResult(int result)
{
    printf("Результат: %i\n", result);
}
