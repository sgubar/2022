#pragma once

int abs_(const int& base)	
{
	return base < 0 ? -base : base;
}

float abs_(const float& base)	
{
	return base < 0 ? -base : base;
}

double abs_(const double& base)
{
	return base < 0 ? -base : base;
}


double pow_(const double& base, const int& power_value)
{
	if (base == 0)				
	{
		return 0;
	}
	double temp_result = 1;		
	for (int i = 0; i < abs_(power_value); i++)	
	{
		temp_result *= base;
	}
	return power_value > 0 ? temp_result : 1.0 / temp_result;	
}

int fact_(const int& base)	
{
	if(base <= 0)	
	{
		return 0;
	}
	int result = 1;	
	for (int i = 1; i <= base; i++)	
	{
		result *= i;
	}
	return result;
}
