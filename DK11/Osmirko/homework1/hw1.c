#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    int i = get_int("Введіть число:");
    int k=0, a[8], count=0;
    while(i>0)
    {
        k = i % 10;
        a[count] = k;
        count++;
        i /= 10;
        if(k != 0 && k != 1)
        {
            printf("Має бути число двійкової системи\n");
            exit(0);
        }
    }
    
    for(int j=0; j<count; j++)
    {
        a[j] *= powered(j);
    }
    int sum = 0;
    for(int j=0; j<count; j++)
    {
        sum += a[j];
    }
    printf("Відповідь:%i\n", sum);
}
