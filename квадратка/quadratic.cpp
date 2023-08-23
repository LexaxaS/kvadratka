#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "tools.h"
//#include "tester.h"
#include "tools.cpp"
//#include "tester.cpp"





int main(void)
{
    printf("\n"
           "# Quadratic equation solver\n"
           "# (c) Lexa, 2023\n\n"
           "Enter 3 numbers\n");

    double roots[2] = {0};

    double a = 0, b = 0, c = 0;

    //tester("tests.txt");
    inPut(&a, &b, &c);

    int nRoots = solveQuadratic(a, b, c, roots);
    ansOut(nRoots, roots);

    return 0;
}



double discr(double a, double b, double c)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    double d = b * b - 4 * a * c;
    return d;
}


int solveQuadratic(double a, double b, double c, double *roots)
{
    assert(roots);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (!isZero(a))
    {
        double d = discr(a, b, c);
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

    else
        return linearSolver(b, c, roots);

}
int linearSolver(double b, double c, double *roots)
{
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
    while (scanf("%lf %lf %lf", a, b, c) != 3 || getchar()!='\n')
    {
        bufClear();
        printf("Please, enter 3 numbers\n");
    }
}


void ansOut(int nRoots, double *roots)
{
    assert(isfinite(nRoots));
    assert(roots);
    switch (nRoots)
    {
        case ZERO_SOL: printf("\nThere are no roots\n\n");
                break;
        case ONE_SOL: printf("\nThe only root is %f\n\n", *roots);
                break;
        case TWO_SOL: printf("\nThe roots are %f, %f\n\n", *roots, *(roots + 1));
                break;
        case ALL_REAL_NUMBERS: printf("\nThe solutions are all real numbers\n\n");
                break;
        default: printf("main():ERROR: nRoots = %d\n\n", nRoots);
    }
}

