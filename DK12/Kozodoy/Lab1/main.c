#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
	float a, b, c;
	input_param(&a, &b, &c);

	float q = qfunc(a, b, c);
	printf("\n%f\n", q);

	return 0;
}