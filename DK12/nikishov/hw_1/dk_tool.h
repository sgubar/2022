/*
Copyright (c) 2021

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

#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef double element;

typedef struct matrix {
	int m;
	int n;
	element ** mat;
} matrix;

/*
 * Function: matrix_init
 *
 * Initialize an empty matrix of specified size.
 *
 * Arguments:
 * 	m - matrix height
 * 	n - matrix weight
 * Return:
 * 	matrix object
 */
matrix matrix_init(int m, int n);

/*
 * Function: matrix_destroy
 *
 * Destroy given matrix and empty allocated memory.
 *
 * Arguments:
 * 	mat - pointer to matrix
 * Return:
 * 	void
 */
void matrix_destroy(matrix * mat);

/*
 * Function: matrix_fill
 *
 * Fill matrix with given value.
 *
 * Arguments:
 * 	mat - pointer to matrix
 * 	x - value to fill matrix with
 * Return:
 * 	void
 */
void matrix_fill(matrix * mat, element x);

/*
 * Function: matrix_enter
 *
 * Fill matrix with data from the user.
 *
 * Arguments:
 * 	mat - pointer to matrix
 * 	s - matrix name
 * Return:
 * 	void
 */
void matrix_enter(matrix * mat, char s);

/*
 * Function: matrix_add
 *
 * Add two matrixes.
 *
 * Arguments:
 * 	a - pointer to the first matrix
 * 	b - pointer to the second matix
 * Return:
 * 	1: specified matrixes have different sizes
 * 	0: success
 */
_Bool matrix_add(const matrix * a, const matrix * b, matrix * res);

/*
 * Function: matrix_print
 *
 * Print given matrix.
 *
 * Arguments:
 * 	mat - pointer to matrix
 * Return:
 * 	void
 */
void matrix_print(const matrix * mat);

#ifdef __cplusplus
}
#endif

#endif // _DK_TOOL_H
