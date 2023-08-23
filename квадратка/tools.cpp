#include <stdio.h>
#include <math.h>
#include "tools.h"

void bufClear(void)
{
    while (getchar() != '\n') { ; }
}

bool isZero(double x)
{
    return fabs(x) < AT;
}
