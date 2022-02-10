#include <stdio.h>
#include <stdlib.h>
#include "dk_strtool.h"

int main(void)
{
    char *test = "   test string with leading and trailing whitespaces     ";
    char *haystack = "this is the haystack that they'll search for the needle";
    char *needle = "th";

    printf("Trimmed string: \n|%s|\n", str_trim(test));
    printf("Word count: \n%i\n", str_count_wrd(test));
    printf("Substring count: \n%i\n", str_count_substr(haystack, needle));
}