#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Point Centre = { 50,50 };
	int R = 10;
	int r = 20;

	Ellipse* El1 = createEllipse(&Centre, &R, &r);

	printEllipse(El1);

	printf("Площа еліпсу: %f\n", SquareOfEllipse(El1));

	destroyEllipse(El1);
	return 0;
}