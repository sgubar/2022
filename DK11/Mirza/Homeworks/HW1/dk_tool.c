#include <math.h>
#include <stdbool.h>
#include "dk_tool.h"

int octal_to_decimal(int num)
{
	int dec = 0, rem = 0, place = 0; 
	while(num != 0)
	{
		rem = num % 10;
		dec = dec + rem * pow(8, place);num = num / 10;
		place++;
	}
	return dec;
}

bool valid (int num)
{
    while (num > 0) 
    {
        int mod = num % 10;
        if (mod > 7)
        return false;
        num = num /10;
    }
    return true;

}