#pragma once

void WARNING();

void get_num(long double* pNUM);

void input_value(long double* pA, long double* pB, long double* pC);

void check_A(long double* pA);
 
void calc_numerator(long double* pNumerator, long double* pA, long double* pB, long double* pC);
void calc_denominator(long double* pDenominator, long double* pB, long double* pC);

void fraction(long double* res_Fraction, long double* pNumerator, long double* pDenominator);

int f_round(long double* pA, int choos);

int sigma(long double* pA, int *pRes_sigma);

void f_Answer(long double* res_Fraction, unsigned long int* res_Sigma);
