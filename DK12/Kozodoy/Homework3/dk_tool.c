#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

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

CircleArr* createCircleArr(int size)
{
	CircleArr* array = (CircleArr*)malloc(sizeof(CircleArr));
	if (array != NULL)
	{
		if (size == 0) {
			printf("ERROR!");
			return NULL;
		}
		array->size = size;
		array->arr = (Circle**)malloc(sizeof(Circle*) * size);
		memset(array->arr, 0, sizeof(Circle*) * size);
	}
	return array;
}

int addCircleToArray(CircleArr* array, Circle* circle)
{
	int index = 0, empty = array->size;
	if (array == NULL)
	{
		return -1;
	}
	for (int i = 0; i < array->size; i++)
	{
		if (array->arr[i] == NULL)
		{
			array->arr[i] = circle;
			index = i;
			break;
		}
		empty--;
		if (empty <= 0)
		{
			printf("ERROR! Out of bounds!\n\n");
			return -1;
		}
	}
	return index;
}

int addCircleAtIndex(CircleArr* array, Circle* circle, int index)
{
	if (array == NULL || index < 0 || index >= array->size)
	{
		return -1;
	}
	array->arr[index] = circle;
	return index;
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

void destroyCircleArr(CircleArr* array)
{
	if (array != NULL)
	{
		if (array->arr != NULL)
		{
			free(array->arr);
		}
		free(array);
	}
}

void infoCircle(Circle* circle)
{
	printf("\tCenter: x = %.2lf; y = %.2lf\n", circle->center->x, circle->center->y);
	printf("\tRadius: %.3lf\n", circle->radius);
	printf("\tArea: %.3lf\n", areaCircle(circle));
}

void infoCircleArr(CircleArr* array)
{
	if (array == NULL)
	{
		return;
	}
	printf("\tArray(%d):\n", array->size);
	for (int i = 0; i < array->size; i++)
	{
		if (array->arr[i] != NULL)
		{
			printf("\nCircle:\n", i);
			printf("\tIndex:  %d\n", i);
			Circle* circle = array->arr[i];
			infoCircle(circle);
		}
		else
		{
			printf("\nCircle:\n", i);
			printf("\tIndex:  %d\n\tNULL\n", i);
		}
	}
}