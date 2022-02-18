#include "matrix2.h"

int main()
{
    int f, z;
    printf("Введіть розмір розмір матриць: \n");
    scanf("%d%d", &f, &z);
    int **matrix = create_matrix(f,z);
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<z;j++)
        {
            *(*(matrix + i) + j) = get_int("Введіть значення для матриці [%d][%d]=",i+1,j+1); // 
        }
    }
printf("Матриця\n");
printarray((int **)matrix,f,z);

    int **matrix1 = create_matrix1(f,z);
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<z;j++)
        {
            *(*(matrix1 + i) + j) = get_int("Введіть значення для матриці [%d][%d]=",i+1,j+1);
        }
    }
printf("Матриця2\n");
printarray((int **)matrix1,f,z);

    int **matrix2 = create_matrix2(f,z);
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<z;j++)
        {
            *(*(matrix2 + i) + j) = *(*(matrix + i) + j) + *(*(matrix1 + i) + j);
            }
        }
printf("\nМатриця-результат\n\n");
printarray((int **)matrix2,f,z);
delete_matrix((int **)matrix,f);
delete_matrix1((int **)matrix1,f);
delete_matrix2((int **)matrix2,f);
return 0;
}
