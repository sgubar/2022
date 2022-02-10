#include <stdlib.h>
#include "dk_strtool.h"

char* str_trim(char* input)
{
    int len = strlen(input);
    int lead = 0;
    int trail = 0;

    while(input[lead] == ' ')
    {
        lead++;
    }
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
char* str_search(char*);
char* str_reverse(char*);
int str_count_char(char*);
int str_count_wrd(char*);
int str_count_substr(char*);
