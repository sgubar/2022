#include <stdlib.h>
#include "dk_strtool.h"

int main(void)
{
    char *test = "   test string with leading and trailing whitespaces     ";
    char *result = str_trim(test);

    printf("\n|%s|\n", result);
}