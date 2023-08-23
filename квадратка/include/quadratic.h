#ifndef QUADRATIC_H
#define QUADRATIC_H

const int dotestslen = 64;
int solveQuadratic(double a, double b, double c, double *roots);
void inPut(double *a, double *b, double *c);
void ansOut(int nRoots, double *roots);
int solveEquation(double a, double b, double c, double *roots);
int linearSolver(double b, double c, double *roots);
double getDiscr(double a, double b, double c);
enum changeNum {ALL_REAL_NUMBERS = -1,
                ZERO_SOL = 0,
                ONE_SOL,
                TWO_SOL};

#endif
