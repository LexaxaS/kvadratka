#ifndef QUADRATIC_H
#define QUADRATIC_H

const double AT = 1e-6;

int solveQuadratic(double a, double b, double c, double *roots);
void inPut(double *a, double *b, double *c);
void ansOut(int nRoots, double *roots);

int linearSolver(double b, double c, double *roots);
double discr(double a, double b, double c);

enum changeNum {ALL_REAL_NUMBERS = -1,
                ZERO_SOL = 0,
                ONE_SOL,
                TWO_SOL};
#endif
