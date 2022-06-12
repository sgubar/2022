#include "dk_tool.h"
int main ()
{
    int n, m, i, j, chyslo;
    printf("Введіть розмір масиву : ");
    scanf("%d %d", &n, &m);

    printf("На яке число будемо множити матрицю? ");
    scanf("%d", &chyslo);

    int **array = create_matrix(n,m);
    fillarray((int **)array,n,m,chyslo);
    printarray((int **)array,n,m);

    delete_matrix((int **)array,n);
}

