#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "square.h"
Point* point_create(const double x, const double y)
{
	Point* tmp = (Point*)malloc(sizeof(Point));
	if(tmp == NULL) return NULL;
	tmp->x = x;
	tmp->y = y;
	return tmp;
}

Square* square_create_arr(Point arr[])
{
	Square* tmp = square_create(arr, (arr+1));
	return tmp;
}

Square* square_create(Point* a, Point* b)
{
	Square* tmp = (Square*)malloc(sizeof(Square));
	if(tmp == NULL) return NULL;
	tmp-> a = a;
	tmp-> b  = b;
	return tmp;
}

Square* square_create_xy(const double ax, const double ay , const double bx, const double by )
{
	Point* a = point_create(ax, ay);
	Point* b = point_create(bx, by);
	Square* tmp = square_create(a, b);
	return tmp;
}

double square_area(Square* sq)
{
	double d = hypot((sq->b->x - sq->a->x), (sq->b->y - sq->a->y));
	return d * d / 2;
}

void square_destroy(Square* sq)
{
	free(sq->a);
	free(sq->b);
	free(sq);
}

void sq_info(Square* sq)
{
	printf("Перший кут: x = %.2lf; y = %.2lf\n", sq->a->x, sq->a->y);
	printf("Другий кут: x = %.2lf; y = %.2lf\n", sq->b->x, sq->b->y);
}
