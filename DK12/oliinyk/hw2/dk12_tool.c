#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "dk12_tool.h"


Point *createPoint(double x, double y) {
	Point *point = (Point *)malloc(sizeof(Point));
	if (point != NULL) {
        point->x = x;
        point->y = y;
    }
	return point;
}

Circle *createCircle(Point *center, Point *edge) {
	Circle *circle = (Circle *)malloc(sizeof(Circle));
	if(circle != NULL) {
        circle->center = center;
        circle->edge = edge;
    }
	return circle;
}

Circle *createCircleXY(double centerX, double centerY, double edgeX, double edgeY) {
	Point *center = createPoint(centerX, centerY);
	Point *edge = createPoint(edgeX, edgeY);
	Circle *circle = createCircle(center, edge);
	return circle;
}

Circle *createArrCircle(Point array[]) {
	Circle *arrayCircle = createCircle(array, (array + 1));
	return arrayCircle;
}

double radiusCircle(Circle *circle) {
    double radius;
    if (circle != NULL) {
        radius = hypot(
            (circle->edge->x - circle->center->x),
            (circle->edge->y - circle->center->y)
        );
    }
    return radius;
}

double areaCircle(Circle *circle) {
    double radius;
    if(circle != NULL) {
        radius = radiusCircle(circle);
        radius = acos(-1) * radius * radius;
    }
    return radius;
}

void destroyCircle(Circle *circle) {
    if(circle != NULL) {
        free(circle->center);
        free(circle->edge);
        free(circle);
    }
}

void printDetailCircle(int count, Circle *arrayCirles[]) {
    if(arrayCirles != NULL) {
        for (int i = 0; i < count; i++) {
            printf("\n");
            printf("Circle № %d:\n", i + 1);
            printf("Center point: x = %.3lf; y = %.3lf\n", arrayCirles[i]->center->x, arrayCirles[i]->center->y);
            printf("Edge point: x = %.3lf; y = %.3lf\n", arrayCirles[i]->edge->x, arrayCirles[i]->edge->y);
            printf("Radius: %.3lf\n", radiusCircle(arrayCirles[i]));
            printf("Area: %.3lf\n", areaCircle(arrayCirles[i]));
            printf("\n");
        }
    }
}