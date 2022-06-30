#include "dk_tool.h"

void main()
{
      int x, y, z;
      printf("Введіть розмір матриці\n");
      printf("[x]: ");
      scanf("%d", &x);
      printf("[y]: ");
      scanf("%d", &y);
      printf("Цифра множення");
      scanf("%d", &z);
      int mat[x][y];
      inputMat(x, y, mat);
      mulMat(z, x, y, mat);
      printMulMat(x, y, mat);
}
