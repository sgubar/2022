#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#ifdef __cplusplus
extern "C" {
#endif
typedef double element;

typedef struct matrix {
	int a;
	int b;
	element **mat;
} matrix;

_Bool arg_check(int argc, char argv);

matrix make_matrix(int a, int b);

void enter_matrix(matrix *mat, char s[]);

void print_matrix(const matrix *mat);

void multiply_matrix(const matrix *y, const matrix *x, matrix *res);


#ifdef __cplusplus
}
#endif

#endif // _DK_TOOL_H				