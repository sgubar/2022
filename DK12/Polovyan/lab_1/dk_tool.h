#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#ifdef __cplusplus
extern "C" {
#endif
	
	int get_A();
	void check_A(int A);
	float get_B();
	float get_C();
	void check_C(float C);
	float calc_up1(int A, float B, float C);
	int calc_fact1(int A);
	void result(float up1, float C, int fact1);
	
#ifdef __cplusplus
}
#endif

#endif
