#include "dk_tool.h"

void inputMat(int x, int y, int mat[x][y])
{
      printf("Значення матриці\n");
      int x1, y1;
      for (x1 = 0; x1 < x; x1++)
      {
            for (y1 = 0; y1 < y; y1++)
            {
                  printf("Введіть цифру[%d][%d] = ", x1 + 1, y1 + 1);
                  scanf("%d", &mat[x1][y1]);
            }
      }
}
void mulMat(int z, int x, int y, int mat[x][y])
{
      int x1, y1;
for (x1 = 0; x1 < x; x1++)
      {
      for (y1 = 0; y1 < y; y1++)
            {
            mat[x1][y1] = (mat[x1][y1]) * z;
            }
      }
}
void printMulMat(int x, int y, int mat[x][y])
{
      int x1, y1;
      for (x1 = 0; x1 < x; x1++)
      {
            for (y1 = 0; y1 < y; y1++)
            {
                  printf("%d  ", mat[x1][y1]);
            }
            printf("\n");
      }
}
