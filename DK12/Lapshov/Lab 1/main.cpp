#include <iostream>
#include "MyMath.h"


double sum_function(const int& end_value, const int& start_value = 0)  
{
    if (start_value > end_value)            
        return 0;
    }
    int sum = 0;   
    for (int current_value = start_value; current_value <= end_value; current_value++) 
    {
        sum += pow_(2, current_value);
    }
    return sum;
}

int main()
{
    double A;
    double B;
    double C;
    

    std::cout << "Enter A(int num >= 0): ";
    std::cin >> A;  
    if (A < 0) 
    {
        std::cout << "Incorrect A value. Program exit." << std::endl;
        return 0;
    }
    std::cout << "Enter B: ";
    std::cin >> B; 
    std::cout << "Enter C( != 0 ): ";
    std::cin >> C;  
    if (C == 0) С
    {
        std::cout << "Incorrect C value. Program exit." << std::endl;
        return 0;
    }
    
    double Q = (abs_(A * C - B) / pow_(C, 3)) * sum_function(A);   

    std::cout << "Result Q: " << Q << std::endl;

    return 0;
}

