#include "T04_PassedExam.h"

bool PassedExam(double points, int N)
{
    if (points < 0 || points > 100)
        throw std::invalid_argument("Points must be in [0,100].");

    int passLimit = 40 + (N % 21); 

    return points > passLimit;
}
