#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "tools.h"
#include "tester.h"
// *argv;../tests/test.txt
//int argc, char *argv[]

int main(int argc, char *argv[])
{
    printf("\n"
           "# Quadratic equation solver\n"
           "# (c) Lexa, 2023\n\n");
    if (argc > 1)
        {
        char *filename = *(argv + 1);
        tester(filename);
        }
    else
        {
        double roots[2] = {0};
        double a = 0, b = 0, c = 0;
        inPut(&a, &b, &c);

        int nRoots = solveEquation(a, b, c, roots);

        ansOut(nRoots, roots);
        return 0;
        }
/*    printf("Do tests?\n");
    char dotests[3] = "";
    scanf("%s", dotests);
    char *dot = dotests;
    bufClear();
    if (!strcmp(dot, "YES") || !strcmp(dot, "yes") || !strcmp(dot, "Yes"))
        tester(filename);*/
}
