#include <stdio.h>
#include <math.h>
#include "../include/tools.h"

void bufClear(void)
{
    while (getchar() != '\n') { ; }
}

bool isZero(double x)
{
    return fabs(x) < AT;
}

bool areEqual(double a, double b)
{
    return fabs(a - b) < AT;
}
