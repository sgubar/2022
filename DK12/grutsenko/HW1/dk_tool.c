#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"
#include "cs50.h"

_Bool arg_check(int argc, char argv)
{
if (argc != 2) {
        printf("You must enter 1 argument\n");
		return 1;      
    } else if (isalpha(argv)) {
          printf("The argument must be a number\n");
		  return 1;          
      } else if (atoi(&argv) < 2) {
            printf("The size must be at least 2x2\n");
			return 1;            
        } else return 0;
}

matrix make_matrix(int a, int b)
{
	matrix tmp;
	tmp.a = a;
	tmp.b = b; 
	tmp.mat = (element**) malloc(a*sizeof(element*));
	for(int i = 0; i < a; i++)
		tmp.mat[i] = malloc(b*sizeof(element));
	return tmp;
}

void enter_matrix(matrix* mat, char s[])
{	
	printf("Enter matrix %s:\n", s);
	for(int i = 0; i < mat->a; i++) {
		for(int j = 0; j < mat->b; j++) {
			printf("%s[%d][%d]: ", s, i, j);
			mat->mat[i][j] = get_double("");
		}
		printf("\n");
	}
}

void multiply_matrix(const matrix* y, const matrix* x, matrix* res)
{	
	
	for(int i = 0; i < y->a; i++) {  
		for(int j = 0; j < x->b; j++) {
			res->mat[i][j] = 0;
            for(int m = 0; m < y->a; m++) {                
                res->mat[i][j] += (y->mat[i][m]) * (x->mat[m][j]);               
            }			
        }
    }		
}

void print_matrix(const matrix *mat)
{
	for(int i = 0; i < mat->a; i++) {
		for(int j = 0; j < mat->b; j++) {
			printf("%lf\t", mat->mat[i][j]);
		}
		printf("\n");
	}
}
