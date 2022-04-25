#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revers()
{
    FILE *file;
    if ((file = fopen("text.txt", "r")) == NULL)
    {
        printf("Error open file\n");
        exit(0);
    }

    char text[256];
    char tmp[256];
    int len;
    while((fgets(text, 256, file)) != NULL)
    {
        len = strlen(text)-1;
        for(int i = 0; i < len; i++)
        {
            tmp[len-i-1] = text[i];
        }
        tmp[len] = '\0';
        printf("%s\n", tmp);
    }
    fclose(file);
}
