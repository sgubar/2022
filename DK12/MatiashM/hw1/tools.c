#include <stdio.h>
#include <math.h>
#include <string.h>
#include "tools.h"

char hex[17];

int get_hexadecimal_number()
{
    printf("Type hexadecimal number: ");
    gets(hex);

    int len = strlen(hex)-1;
    return len;
}

int transformation_number(int len)
{
    int val;
    int decimal = 0;

    for(int i=0;hex[i]!='\0';i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i]-48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i]-97+10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i]-65+10;
        }

        decimal += val*pow(16, len);
        len--;
    }
    return decimal;
}

void print_result(int decimal)
{
    printf("Hexadecimal number = %s\n", hex);
    printf("Decimal number = %d", decimal);
}