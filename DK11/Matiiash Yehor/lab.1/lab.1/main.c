#include "func.h"

int  main(int argc, char* argv[])
{  
   unsigned int var_a = valid_value_a();
   double var_b = valid_value_b();
   unsigned int var_c = valid_value_c();

   if(var_b + var_c < 0)
   {
      printf("-----COMPLEX SQUARE ROOT. PLEASE CHOOSE ANOTHER <<B>> OR <<C>>-----\n");
   }
   else
   {
      printf("RESULT %.3f\n", q(var_a,var_b,var_c));
   }
return 0;
}