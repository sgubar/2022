#include "math.h"

#define MOD(n) (n < 0 ? -n : n)

double abs_extend (double A)
	{
	if (A < 0)
	{
	return -A;
	}
	else
	{
	return A;
	}

double power(int base, int pow) 
	{
	double result = 1;
	int pw = MOD(pow);
	for (int i = 0; i < pw; i ++) 
	{
		result *= base;
	}

	return (pow < 0) ? 1.0 / result : result;
	}

long sum_suma(int A, int D, double res) 
	{
	long result = 0;
	for (int i = D; i < A; i ++) 
	{
	result += (res);
	}
	return result;
	}
 
double q (int A, int B, int C)
	{
	double result = 0;
	return ((abs_extend(A*B-C) / (double)power(C, 3)) * (double)sum_suma(D, A, power(2, D));
	}
