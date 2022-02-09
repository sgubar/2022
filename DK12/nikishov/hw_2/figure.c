/*
Copyright (c) 2022 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "figure.h"

Point* pt_create(const double x, const double y)
{
	Point* tmp = (Point*)malloc(sizeof(Point));
	if(tmp == NULL) return NULL;
	tmp->x = x;
	tmp->y = y;
	return tmp;
}

Square* sq_create_arr(Point arr[])
{
	Square* tmp = sq_create(arr, (arr+1));
	return tmp;
}

Square* sq_create(Point* fc, Point* sc)
{
	Square* tmp = (Square*)malloc(sizeof(Square));
	if(tmp == NULL) return NULL;
	tmp->fc = fc;
	tmp->sc = sc;
	return tmp;
}

Square* sq_create_xy(const double fcx, const double fcy, const double scx, const double scy)
{
	Point* fc = pt_create(fcx, fcy);
	Point* sc = pt_create(scx, scy);
	Square* tmp = sq_create(fc, sc);
	return tmp;
}

double sq_area(Square* sq)
{
	double d = hypot((sq->sc->x - sq->fc->x), (sq->sc->y - sq->fc->y));
	return d * d / 2;
}

void sq_destroy(Square* sq)
{
	free(sq->fc);
	free(sq->sc);
	free(sq);
}

void sq_info(Square* sq)
{
	printf("First  corner: x = %.2lf; y = %.2lf\n", sq->fc->x, sq->fc->y);
	printf("Second corner: x = %.2lf; y = %.2lf\n", sq->sc->x, sq->sc->y);
}

