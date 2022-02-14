#include <stdio.h>
#include <stdlib.h>
#include "dk_strtool.h"

int main(void)
{
    char *simple_cons = "fd ff   f    f  k";
    char *cons_test = "  string with consecutive        spaces";
    char *test = "   test string with leading and trailing whitespaces     ";
    char *haystack = "this is the haystack that they'll search for the needle";
    char *needle = "th";

    printf("Trimmed string: \n|%s|\n", str_trim(cons_test));
    printf("Word count: \n%i\n", str_count_wrd(simple_cons));
    printf("Substring count: \n%i\n", str_count_substr(haystack, needle));
}