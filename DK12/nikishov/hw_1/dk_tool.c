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

#include <stdlib.h>
#include <stdio.h>

#include "dk_tool.h"

matrix matrix_init(int m, int n)
{
	matrix tmp;
	tmp.m = m;
	tmp.n = n;
	tmp.mat = (element**) malloc(m*sizeof(element*));
	for(int i = 0; i < m; i++)
		tmp.mat[i] = malloc(n*sizeof(element));
	return tmp;
}

void matrix_destroy(matrix * mat)
{
	for(int i = 0; i < mat->m; i++)
		free(mat->mat[i]);
	free(mat->mat);
}


void matrix_fill(matrix * mat, element x)
{
	for(int i = 0; i < mat->m; i++)
		for(int j = 0; j < mat->n; j++)
			mat->mat[i][j] = x;
}

void matrix_enter(matrix * mat, char s)
{
	printf("Please enter matrix %c:\n", s);
	for(int i = 0; i < mat->m; i++) {
		for(int j = 0; j < mat->n; j++) {
			printf("%c[%d][%d]: ", s, i, j);
			scanf("%lf", &mat->mat[i][j]);
		}
		putchar('\n');
	}
}

_Bool matrix_add(const matrix * a, const matrix * b, matrix * res)
{
	if(a->m != b->m || a->n != b->n) return 1;
	if(a->m != res->m || a->n != res->n) return 1;
	for(int i = 0; i < a->m; i++)
		for(int j = 0; j < a->n; j++)
			res->mat[i][j] = a->mat[i][j] + b->mat[i][j];
	return 0;
}

void matrix_print(const matrix * mat)
{
	for(int i = 0; i < mat->m; i++) {
		for(int j = 0; j < mat->n; j++)
			printf("%3.2lf ", mat->mat[i][j]);
		putchar('\n');
	}
}
