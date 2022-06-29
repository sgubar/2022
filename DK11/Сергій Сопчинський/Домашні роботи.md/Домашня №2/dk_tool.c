#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Point* createPoint(double x, double y) 
{
	Point* point = (Point*)malloc(sizeof(Point));
	if (point != NULL) 
	{
		point->x = x;
		point->y = y;
	}
	return point;
}
Circle* createCircle(Point* center, double radius)
{
	Circle* circle = (Circle*)malloc(sizeof(Circle));
	if (circle != NULL)
	{
		circle->center = center;
		circle->radius = radius;
	}
	return circle;
}
Circle* createCirclePoints(Point* center, Point* rad)
{
	double radius = hypot((center->x - rad->x), (center->y - rad->y));
	Circle* circle = createCircle(center, radius);
	return circle;
}
Circle* createCircleCoord(double centerX, double centerY, double x, double y)
{
	Point* center = createPoint(centerX, centerY);
	double radius = hypot(centerX - x, centerY - y);
	Circle* circle = createCircle(center, radius);
	return circle;
}
double areaCircle(Circle* circle)
{
	double area;
	if (circle != NULL)
	{
		double radius = circle->radius;
		area = M_PI * radius * radius;
	}
	return area;
}
void destroyCircle(Circle* circle)
{
	free(circle->center);
	free(circle);
}
void infoCircle(Circle* circle)
{
	printf("\nCircle:\n");
	printf("\tCenter: x = %.2lf; y = %.2lf\n", circle->center->x, circle->center->y);
	printf("\tRadius: %.3lf\n", circle->radius);
	printf("\tArea: %.3lf\n", areaCircle(circle));
}
