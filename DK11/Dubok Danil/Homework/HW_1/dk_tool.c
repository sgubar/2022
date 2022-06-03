#include <stdio.h>

void transp_mat(int x, int y, int q, int w, int a, int s)
{
      printf("Привіт, укажіть розмір матриці яку збираєтесь транспонувати [x][y]\n");
      printf("Спочатку [x]: ");
      scanf("%d", &x);
      printf("Тепер [y]: ");
      scanf("%d", &y);
      int mat[x][y];
      printf("Наступним кроком укажіть усі складові матриці\n");
      for (q = 0; q < x; q++)
      {
            for (w = 0; w < y; w++)
            {
                  printf("Вкажічь число[%d][%d] = ", q + 1, w + 1);
                  scanf("%d", &mat[q][w]);
            }
      }
      printf("Ваша матриця: \n");
      q = x;
      w = y;
      for (q = 0; q < x; q++)
      {
            for (w = 0; w < y; w++)
            {
                  printf("%d  ", mat[q][w]);
            }
            printf("\n");
      }
      int tmat[a][s];
      printf("Транспонована матриця: \n");
      a = x;
      s = y;
      for (a = 0; a < y; a++)
      {
            for (s = 0; s < x; s++)
            {
                  printf("%d  ", tmat[s][a]);
            }
            printf("\n");
      }
}