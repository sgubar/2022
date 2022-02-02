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
#include <ctype.h>

#include "dk_tool.h"

int main(int argc, char * argv[])
{
	/* Parsing shell arguments */
	if(argc != 3) {
		fprintf(stderr, "Usage: %s i j\n\nArguments:\n\ty - matrix height\n\tx - matrix lenght\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	unsigned int i, j; // Matrix dimensions.
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	if(i == 0 || j == 0) {
		fprintf(stderr, "Error: arguments should be numerical and non-zero.\n");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("i: %d\nj: %d\n", i, j);
#endif

	matrix a = matrix_init(i, j);
	matrix b = matrix_init(i, j);
	matrix z = matrix_init(i, j);

	matrix_enter(&a, 'A');
	matrix_enter(&b, 'B');

	if(matrix_add(&a, &b, &z)) {
#ifdef DEBUG
		fprintf(stderr, "Error: uncompatible matrix size.\n");
#endif
		exit(EXIT_FAILURE);
	}
	
	printf("Result:\n\n");
	matrix_print(&z);

	matrix_destroy(&a);
	matrix_destroy(&b);
	matrix_destroy(&z);
	exit(EXIT_SUCCESS);
}
