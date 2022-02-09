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

#ifndef _FIGURE_H
#define _FIGURE_H

typedef struct point {
	double x;
	double y;
} Point;

typedef struct square {
	Point* fc; // First corner.
	Point* sc; // Second corner.
} Square;

Point* pt_create(const double x, const double y);

Square* sq_create_arr(Point arr[]);
Square* sq_create(Point* fc, Point* sc);
Square* sq_create_xy(const double fcx, const double fcy, const double scx, const double scy);
double sq_area(Square* sq);
void sq_destroy(Square* sq);
void sq_info(Square* sq);

#endif // _FIGURE_H
