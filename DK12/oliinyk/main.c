#include <stdio.h>


int main(void)
{
    char input;
    int response = 0;
    while(scanf("%c", &input)==1)
    {
        if (input != '0' && input != '1')
        {
            if (input == '\n') break;
            return printf("Only binary number!");
        }
        response = response * 2 + (input - '0');
    }
    return printf("Result: %i\n", response);
}