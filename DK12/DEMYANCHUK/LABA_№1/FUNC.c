#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "Header.h"

void WARNING() {
	printf("\n\n%s\n\n", "WARNING -- IF VARIABLE A > 15 SIGMA WILL CALCULATED WITH UP LIMIT 15 (FRACTION WILL CALCULATED WITH PREVIOUS VALUE!)");
}

void input_value(long double* pA, long double* pB, long double* pC) {
	printf("Enter three real number:\n");

	do {	
		printf("A = "); get_num(pA); 
		printf("B = "); get_num(pB);
		printf("C = "); get_num(pC);

		if (100 - *pB - *pC == 0) printf("\n100 - B - C = 0\nenter deferant three real number:\n\n");

	} while (100 - *pB - *pC == 0);
}

void check_A(long double* pA) {
	//to calculate sigma variable A have to have int type
	if (*pA == 0.0) return;

	do
	{
		if (*pA < 0.0) {
			printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			printf("%s\n", "variable A < 0, to calculate sigma A must be >= 0");
			printf("%s\n", "fractoin will be calculated with previous value of variable A!");
			printf("%s\n", "please, enter new value of variable A >= 0");
			printf("%s", "new value of variable A = "); scanf("%lf", pA);
		}

		if (*pA > 0.0 && *pA < 1.0) {
			printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			printf("%s\n", "variable A isnt int");
			printf("%s\n", "to calculated sigma A must be int");
			printf("%s\n", "please, enter new value of variable A");
			printf("%s", "new value of variable A = "); scanf("%lf", pA);
		}
	} while (*pA < 1);
}

void get_num(long double* pNUM) {
	int code = 0;

	do
	{
		scanf("%lf", pNUM);
		code = getchar();
		if (code != 10) {
			printf("%s\n", "entered symbol isnt int, please repeat");
		}
	} while (code != 10);
}

void calc_numerator(long double* pNumerator, long double* pA, long double* pB, long double* pC) {
	*pNumerator = (*pA + *pB + *pC);
}
void calc_denominator(long double* pDenominator, long double* pB, long double* pC) {
	*pDenominator = (100 - *pB - *pC);
}

void fraction(long double* res_Fraction, long double* pNumerator, long double* pDenominator) {
	*res_Fraction = (*pNumerator / *pDenominator);
}

int f_round(long double* pNUM, int choos) {
	if (*pNUM < 0) {
		if (choos == 1) return ((int)*pNUM * (-1));
		if (choos == 2) return (((int)*pNUM) * (-1) + 1);
	}

	if (*pNUM >= 0) {
		if (choos == 1) return ((int)*pNUM);
		if (choos == 2) return (((int)*pNUM) + 1);
	}
}

int sigma(long double* pNUM, int* pRes_sigma) {	
	check_A(pNUM);

	if (*pNUM > 15) {
		*pNUM = 15;
	}

	// A = 0
	if (*pNUM == 0) {	
		*pRes_sigma = pow(2, *pNUM);
		return 0;
	}

	// A > 0	
	if (*pNUM > 0) {
		for (int D = 0; D <= *pNUM; D++) {
			int A_temp = (D + *pNUM);	
			*pRes_sigma = *pRes_sigma + pow(2, A_temp);
		}
	}
}

void f_Answer(long double* res_Fraction, unsigned long int* res_Sigma) {
	printf("%lf\n", (*res_Fraction + *res_Sigma));
}
