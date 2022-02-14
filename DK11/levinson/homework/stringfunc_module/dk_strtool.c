#include <stdlib.h>
#include "dk_strtool.h"

char* str_trim(char* input)
{
    if(input == NULL)
    {
        printf("\nNULL pointer passed to str_trim funciton!\n");
        return NULL;
    }

    int len = strlen(input);
    int lead = 0;
    int trail = 0;

    while(input[lead] == ' ')
    {
        lead++;
    }

    if(lead == len)
        return NULL;

    while(input[(len - 1) - trail] == ' ')
    {
        trail++;
    }

    len = len - (trail + lead);

    char *trimmed = malloc(sizeof(char) * len + 1); 
    memcpy(trimmed, &input[lead], sizeof(char) * len);
    trimmed[len] = '\0';

    return trimmed;
};
int str_count_wrd(char* input)
{
    if(input == NULL)
    {
        printf("\nNULL pointer passed to str_count_wrd funciton!\n");
        return 0;
    }

    input = str_trim(input);

    if(input == NULL)
        return 0;

    int len = strlen(input);
    int wrds = 1;

    for(int i = 1; i < len; i++)
    {
        if(input[i] == ' ')
            wrds++;
    }

    return wrds;
};
void cnt_sub(char *str, char *sub, int *ptr)
{
    if(str == NULL || sub == NULL || ptr == NULL)
    {
        printf("\nNULL pointer passed to cnt_sub funciton!\n");
        return 0;
    }

    int hay = strlen(str);
    int ndl = strlen(sub);

    if(hay >= ndl)
    {
        int i = 0;

        while(i < ndl)
        {
            if(str[i] != sub[i])
            {
                i++;
                goto rec;
            }

            i++;
        }
        
        *ptr += 1;
        rec:
        cnt_sub(&str[i], sub, ptr);
    }

    return;
};
int str_count_substr(char *str, char *sub)
{
    if(str == NULL || sub == NULL)
    {
        printf("\nNULL pointer passed to str_count_substr funciton!\n");
        return 0;
    }

    int result = 0;
    cnt_sub(str, sub, &result);

    return result;
};