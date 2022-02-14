#include "math.h"
#define MOD(n) (n<0 ? -n : n)
double power(int base, int pow);
{
    double result = 1;
    int pw = MOD (pow); 
    for (int i =0, i< pw ; i++)
    {
       result *=base;
        }
 return (pow <0) ? 1.0/base : base;
}
long sum_factor(int start, int finish);
{
   long result = 0;
    for (int i= start; i<finish; i++ )
    {
             result +=factorial(i + finish);

    }

    return  result;
}
long factorial(int base);
{
    long result = 1;
    if (number<0){
        return -1;
    }
    for (int i = 1; i <=numeber ; i ++){
        result *=i;
    }
return result; 
}
double  q(int A,int B,int C);
{
    
    return power (A*B)/(double)(B+power(C, 2))+(double)sum_factor(0, B); 
}
