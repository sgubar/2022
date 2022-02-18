#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

int get_A()
{
	int A1;
	printf("Print A:\n");
	scanf("%d", &A1);
	return A1;
}

void check_A(int A)
{
	if (A < 1 || A % 1 != 0)
	{
		printf("A MUST BE INTEGER AND MUST BE > 0 !!!\n");
		exit(0);
	}
}

float get_B()
{
	float B1;
	printf("Print B:\n");
	scanf("%f", &B1);
	return B1;
}

float get_C()
{
	float C1;
	printf("Print C:\n");
	scanf("%f", &C1);
	return C1;
}

void check_C(float C)
{
	if (C == 0)
	{
		printf("C MUST NOT BE 0 !!!\n");
		exit(0);
	}
}

float calc_up1(int A, float B, float C)
{
	float up = A * C - B;
	if (up < 0)
	up = up * (-1);
	return up;
}

int calc_fact1(int A)
{
	float fact;
	for (int d = 0; d <= A; d++)
	{
		fact = fact + pow(2, d);
	}
	return fact;
}

void result(float up1, float C, int fact1)
{
	float res = (up1 / (C * C * C) * fact1);
	printf("Result: %f\n", res);
}
