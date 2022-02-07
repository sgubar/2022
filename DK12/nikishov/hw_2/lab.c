#include <cmath>

#include "lab.h"

num factorial(const num n)
{
	num f = 1;
	for(unsigned i = 1; i <= n; i++) f *= (num)i;
	return f;
}

num sqroot(const num n) { return sqrt(n); }

