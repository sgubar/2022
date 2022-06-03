#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

char wordsArray[100][100];
int max = 0;

int checkNumber(int count) 
{
    if (count <= 100)
    {
        return 1;
    }
    printf("Максимум - 100!\n");
    exit(0);
}

void checkMaxCount(int count) 
{
    if (count > max) 
    {
        max = count;
    }
}

int getCount(void) 
{
    int count;
    printf("Введіть кількість слів (максимальна - 100): ");
    scanf("%d", &count);
    checkNumber(count);
    return count;
}

void getWords(int count) 
{
    printf("Введіть слова:\n");
    for (int i = 0; i < count; i++) 
    {
        scanf("%s", &wordsArray[i][0]);
    }
    printf("\n");
}

void sortArray(int count) 
{
    int sortComplete;

    for (int i = count - 1; i >= 0; i--) 
    {
        sortComplete = 1;
        for (int j = 0; j < i; j++) 
        {
            checkMaxCount(strlen(wordsArray[j]));
            if (strlen(wordsArray[j]) > strlen(wordsArray[j + 1])) 
            {
                char tmp[strlen(wordsArray[j])];
                char tmp2[strlen(wordsArray[j + 1])];

                for (int k = 0; k <= strlen(wordsArray[j]); k++) 
                {
                    tmp[k] = wordsArray[j][k];
                }
                for (int k = 0; k <= strlen(wordsArray[j + 1]); k++) 
                {
                    tmp2[k] = wordsArray[j + 1][k];
                }

                for (int k = 0; k <= strlen(wordsArray[j]); k++) 
                {
                    wordsArray[j][k] = '\0';
                }
                for (int k = 0; k <= strlen(wordsArray[j + 1]); k++) 
                {
                    wordsArray[j + 1][k] = '\0';
                }

                for (int k = 0; k <= strlen(wordsArray[j]); k++) 
                {
                    wordsArray[j][k] = tmp2[k];
                }
                for (int k = 0; k <= strlen(wordsArray[j + 1]); k++) 
                {
                    wordsArray[j + 1][k] = tmp[k];
                }

                sortComplete = 0;
            }
        }
        if (sortComplete == 1) 
        {
            break;
        }
    }
    printf("\n");
}


void printArray(int count) 
{
    printf("Відсортований масив:\n");
    for (int i = 0; i < count; i++) 
    {
        printf("%s ", wordsArray[i]);
    }
    printf("\n\n");
}

void printMaxLettersWords(int count) 
{
    printf("Максимальна довжина у масиві - %d:\n", max);
    for (int i = 0; i < count; i++) 
    {
        if (strlen(wordsArray[i]) == max) 
        {
            printf("%s ", wordsArray[i]);
        }
    }
    printf("\n");
}
