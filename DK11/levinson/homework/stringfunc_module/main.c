#include <stdio.h>
#include <stdlib.h>
#include "dk_strtool.h"

int main(void)
{
    char *test = "   test string with leading and trailing whitespaces     ";
    char *result = str_trim(test);
    int num = str_count_wrd(test);

    printf("\n|%s|\n", result);
    printf("\n%i\n", num);
}