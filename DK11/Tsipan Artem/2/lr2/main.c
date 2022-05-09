#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    while(1)
    {
        printf("Enter path to .c/.cpp file or 'qqq' to exit program: ");
        char buf[256];
        gets(buf);
        if(strcmp("qqq", buf) == 0) return 0;
        else
        {
            FILE* f = fopen(buf, "r");
            if(f == NULL)
            {
                printf("Error reading file!\n");
                continue;
            }
            int balance = 0;
            while(!feof(f))
            {
                char c = fgetc(f);
                if(c == '{') balance++;
                else if(c == '}') balance--;
            }
            if(balance == 0) printf("Parentheses are balanced\n");
            else printf("Parentheses are not balanced! %i bracket(s) %s\n.", abs(balance), balance < 0 ? "redunant" : "lacks");
            fclose(f);
        }
    }
}
