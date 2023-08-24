#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../include/quadratic.h"
#include "../include/tools.h"
#include "../include/tester.h"
// *argv;../tests/test.txt
//int argc, char *argv[]

int solveQuadratic(double a, double b, double c, double *roots);
int linearSolver(double b, double c, double *roots);
double getDiscr(double a, double b, double c);

double getDiscr(double a, double b, double c)
{
    MY_ASSERT(isfinite(a));
    MY_ASSERT(isfinite(b));
    MY_ASSERT(isfinite(c));

    return b * b - 4 * a * c;
}

int solveEquation(double a, double b, double c, double *roots)
{
    MY_ASSERT(roots);
    MY_ASSERT(isfinite(a));
    MY_ASSERT(isfinite(b));
    MY_ASSERT(isfinite(c));

    if (!isZero(a))
        return solveQuadratic(a, b, c, roots);
    else
        return linearSolver(b, c, roots);
}

int solveQuadratic(double a, double b, double c, double *roots)
{

    MY_ASSERT(isfinite(a));
    MY_ASSERT(isfinite(b));
    MY_ASSERT(isfinite(c));
    MY_ASSERT(roots);

    double d = getDiscr(a, b, c);
    if (d > 0)
    {
        double sqd = sqrt(d);
        double x1 = (-b + sqd) / 2.0;
        double x2 = (-b - sqd) / 2.0;
        *roots = x1;
        *(roots + 1) = x2;
        return TWO_SOL;
    }

    else if (isZero(d))
    {
        double x1 = -b / 2.0;
        *roots = x1;
        return ONE_SOL;
    }

    else
        return ZERO_SOL;
}

int linearSolver(double b, double c, double *roots)
{
    MY_ASSERT(isfinite(b));
    MY_ASSERT(isfinite(c));
    MY_ASSERT(roots);

    if (!isZero(b))
    {
        *roots = -c / b ;
        return ONE_SOL   ;
    }

    else
    {
        if (isZero(c))
            return ALL_REAL_NUMBERS;
        else
            return ZERO_SOL ;
    }
}

void inPut(double *a, double *b, double *c)
{
    while (scanf("%lf %lf %lf", a, b, c) != 3 || getchar() != '\n')
    {
        bufClear();
        printf("Please, enter 3 numbers\n");
    }
}

void ansOut(int nRoots, double *roots)
{
    MY_ASSERT(isfinite(nRoots));
    MY_ASSERT(roots);

    switch (nRoots)
    {
        case ZERO_SOL:
            printf("\nThere are no roots\n\n");
            break;
        case ONE_SOL:
            printf("\nThe only root is %f\n\n", *roots);
            break;
        case TWO_SOL:
            printf("\nThe roots are %f, %f\n\n", *roots, *(roots + 1));
            break;
        case ALL_REAL_NUMBERS:
            printf("\nThe solutions are all real numbers\n\n");
            break;
        default:
            printf("main():ERROR: nRoots = %d\n\n", nRoots);
    }
}

