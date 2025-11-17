#include "T02_CalculateShipping.h"

double CalculateShipping(double weightKg, bool express, int N)
{
    if (weightKg < 0)
        throw std::invalid_argument("Weight cannot be negative.");

    if (weightKg == 0)
        return 0.0;

    double freeLimit = 5 + (N % 4);               
    double baseSmall = 2.0 + (N % 3) * 0.5;       
    double baseMedium = baseSmall + 2.0;          
    double baseLarge = baseMedium + 5.0;          
    double expressFactor = 1.3 + (N % 3) * 0.1;   

    double cost = 0;

    if (weightKg <= 1)
        cost = baseSmall;          
    else if (weightKg <= freeLimit)
        cost = baseMedium;         
    else
        cost = baseLarge;         

    if (express)
        cost *= expressFactor;     

    return cost;
}
