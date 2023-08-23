#include <stdio.h>
#include <math.h>
#include "tester.h"


char filetest[] = "tests.txt";
int c = 0;
void tester(char *filetest)
{
    double roots[2] = {0};
    double a = 0, b = 0, c = 0;
    fp = fopen(filetest, "r");
    double rightnRoots = 0, rightx1 = 0, rightx2 = 0;
    while (fscanf(fp, "%lf %lf %lf %lf %lf %lf\n", &a, &b, &c, &rightnRoots, &rightx1, &rightx2) == 6)
    {
        int nRoots = solveQuadratic(a, b, c, roots);
        if (nRoots == rightnRoots)
        {
            if (*(roots) == rightx1 && *(roots + 1) == rightx2)
            {
                c++;
            }
        }
    }
}
