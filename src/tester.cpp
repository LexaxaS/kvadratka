#include <stdio.h>
#include <math.h>
#include "tester.h"
#include "quadratic.h"
#include "tools.h"

void tester(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("FILE_ERROR\n");
        return ;
    }
    int cnt = 0;
    double roots[2] = {0};
    double a = 0, b = 0, c = 0;
    double rightnRoots = 0, rightx1 = 0, rightx2 = 0;
    while (fscanf(fp, "%lf %lf %lf %lf %lf %lf\n", &a, &b, &c, &rightnRoots, &rightx1, &rightx2) == 6)
    {
        printf("%lf %lf %lf %lf %lf %lf", a, b, c, rightnRoots, rightx1, rightx2);
        int nRoots = solveEquation(a, b, c, roots);
        if (areEqual(nRoots, rightnRoots))
        {
            if (areEqual(*(roots), rightx1) && areEqual(*(roots + 1), rightx2))
            {
                printf("    Success\n");
                cnt++;
            }
            else
                printf("    Fail\n");
        }
        else
            printf("    Fail\n");
    }
    int fls = length - cnt;
    printf("Tests failed: %d", fls);
}
