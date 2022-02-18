#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.c"

int main()
{
	int A = get_A();
	check_A(A);
	float B = get_B();
	float C = get_C();
	check_C(C);

	int fact1 = calc_fact1(A);
	float up1 = calc_up1(A, B, C);

	result(up1, C, fact1);
	return 1;
}
