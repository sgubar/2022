#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
  
_Bool valid (int num);
int main(void)  
{  
    int num, dec; 
  
    printf("Enter an octal number not higher than 4-digits\n");  
    scanf("%d", &num);  

    if(num > 9999) 
    {
        printf("Number should be less than 4 digits.\n");
        exit(EXIT_FAILURE);
    }
    if(!valid(num)) 
    {
        printf("Non octal numbers entered.\n");
        exit(EXIT_FAILURE);
    }
    printf("\n%d in decimal is ", num);  
    dec = octal_to_decimal(num);
    printf("%d\n", dec);  
  
    return 0;  
}
