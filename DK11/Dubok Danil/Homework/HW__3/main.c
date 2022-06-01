#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "trap.h"
#include "array.h"

void main()
{
      help();
      char Am = 'A', Bm = 'B', Cm = 'C', Dm = 'D', xm = 'x', ym = 'y';

      int Ax = inputC(Am, xm);
      int Ay = inputC(Am, ym);
      int Bx = inputC(Bm, xm);
      int By = inputC(Bm, ym);
      int Cx = inputC(Cm, xm);
      int Cy = inputC(Cm, ym);
      int Dx = inputC(Dm, xm);
      int Dy = inputC(Dm, ym);

      IP *A = createPoint(Ax, Ay);
      IP *B = createPoint(Bx, By);
      IP *D = createPoint(Dx, Dy);
      IP *C = createPoint(Cx, Cy);

      IT *t = createTrap(A, B, C, D);

      printTrap(t);
      printf("\n");
      printf("\n");
      printf("\n");

      Array *array = createArrayTrap(4);
      printArray(array);
      printf("\n");
      setTrapAtIndex(array, t, 0);
      printArray(array);
      printf("\n");
      setTrapAtIndex(array, t, 5);
      printArray(array);
      printf("\n");
      delitTrap(t);

      deleteArray(array);
}
