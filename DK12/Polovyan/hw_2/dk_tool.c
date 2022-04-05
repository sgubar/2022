#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


#include "dk12_tool.h"


Point *createPoint(double x, double y) {
	Point *point = (Point *)malloc(sizeof(Point));
	if (point != NULL) {
        point->x = x;
        point->y = y;
    }
	return point;
}

Elips *createElips(Point *center, Point *edge_a, Point *edge_b) {
	Elips*elipse = (Elips *)malloc(sizeof(Elips));
	if(elipse != NULL) {
        elipse->center = center;
        elipse->edge_a = edge_a;
        elipse->edge_b = edge_b;
    }
	return elipse;
}

Elips *createElipsXY(double centerX, double centerY, double edge_aX, double edge_aY, double edge_bX, double edge_bY) {
	Point *center = createPoint(centerX, centerY);
	Point *edge_a = createPoint(edge_aX, edge_aY);
	Point *edge_b = createPoint(edge_bX, edge_bY);
	Elips *elips = createElips(center, edge_a, edge_b);
	return elips;
}

double hypot_a_Elips(Elips *elips) {
    double hypotenuse_a;
    hypotenuse_a = hypot(
        (elips->edge_a->x - elips->center->x),
        (elips->edge_a->y - elips->center->y)
    );
    return hypotenuse_a;
}

double hypot_b_Elips(Elips *elips) {
    double hypotenuse_b;
    hypotenuse_b = hypot(
        (elips->edge_b->x - elips->center->x),
        (elips->edge_b->y - elips->center->y)
    );
    return hypotenuse_b;
}

double areaElips(Elips *elips) {
    double hypotenuse_a = hypot_a_Elips(elips);
    double hypotenuse_b = hypot_b_Elips(elips);
    double area = acos(-1) * hypotenuse_a * hypotenuse_b;
    return area;
}

Elips *createArrElips(Point *array[]) {
	Elips *arrayElips = createElips(*array, (*array + 1), (*array + 2));
	return arrayElips;
}

void destroyElips(int count, Elips *arrayElips[]) {
    for (int i = 0; i < count; i++) {
        if(arrayElips[i] != NULL) {
            free(arrayElips[i]->center);
            free(arrayElips[i]->edge_a);
            free(arrayElips[i]->edge_b);
            free(arrayElips[i]);
        }
    }
}

void printDetailElips(int count, Elips *arrayElips[]) {
    for (int i = 0; i < count; i++) {
        if(arrayElips[i] != NULL) {
            printf("\n");
            printf("Elips № %d:\n", i + 1);
            printf("Center point: x = %.3lf; y = %.3lf\n", arrayElips[i]->center->x, arrayElips[i]->center->y);
            printf("Edge a point: x = %.3lf; y = %.3lf\n", arrayElips[i]->edge_a->x, arrayElips[i]->edge_a->y);
            printf("Edge b point: x = %.3lf; y = %.3lf\n", arrayElips[i]->edge_b->x, arrayElips[i]->edge_b->y);
            printf("1st semiaxis: %.3lf;\n", hypot_a_Elips(arrayElips[i]));
            printf("2nd semiaxis: %.3lf;\n", hypot_b_Elips(arrayElips[i]));
            printf("Elips area: %.3lf;\n", areaElips(arrayElips[i]));
            printf("\n");
        }
    }
}
