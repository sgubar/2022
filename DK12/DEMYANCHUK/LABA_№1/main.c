#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "Header.h"

int main(int argc, const char* argv[]) {

	while (1){
	long double A = 0.0, B = 0.0, C = 0.0;

	long double numerator = 0.0;
	long double denominator = 0.0;
	long double res_Fraction = 0.0;
	unsigned long int res_Sigma = 0;

	long double* pA = &A;
	long double* pB = &B;
	long double* pC = &C;

	//WARNING
	WARNING();
	
	//get value from user
	input_value(&A, &B, &C);

	//calculate numerator and denominator
	calc_numerator(&numerator, &A, &B, &C);
	calc_denominator(&denominator, &B, &C);

	//fraction
	fraction(&res_Fraction, &numerator, &denominator);

	//calculate sigma(sum)
	sigma(&A, &res_Sigma);

	//print answer
	f_Answer(&res_Fraction, &res_Sigma);

	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
	}

	return 0;

}
