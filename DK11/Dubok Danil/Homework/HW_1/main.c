
#include "dk_tool.h"

void main(){
      int x, y;
      printf("Привіт, укажіть розмір матриці яку збираєтесь транспонувати [x][y]\n");
      printf("Спочатку [x]: ");
      scanf("%d", &x);
      printf("Тепер [y]: ");
      scanf("%d", &y);
      int mat[x][y];
      inputMatrix(x, y, mat);
      printFirstMatrix(x, y, mat);
      printTranspMatrix(x, y, mat);
}