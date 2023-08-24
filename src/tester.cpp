#include <stdio.h>
#include <math.h>
#include "../include/tester.h"
#include "../include/quadratic.h"

void tester(char *filename)
{
    int cnt = 0;
    double roots[2] = {0};
    double a = 0, b = 0, c = 0;
    FILE *fp = fopen(filename, "r");
    double rightnRoots = 0, rightx1 = 0, rightx2 = 0;
    if (fp == NULL)
    {
        printf("FILE_ERROR\n");
        return ;
    }
    while (fscanf(fp, "%lf %lf %lf %lf %lf %lf\n", &a, &b, &c, &rightnRoots, &rightx1, &rightx2) == 6)
    {
        printf("%lf %lf %lf %lf %lf %lf", a, b, c, rightnRoots, rightx1, rightx2);
        int nRoots = solveEquation(a, b, c, roots);
        if (nRoots == rightnRoots)
        {
            if (*(roots) == rightx1 && *(roots + 1) == rightx2)
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
