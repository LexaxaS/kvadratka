//! @file

#ifndef QUADRATIC_H
#define QUADRATIC_H

/**
* @brief A better assert
*
* @param [in] cond condition
*
* Prints file, line and function that failed
*/
#define MY_ASSERT( cond )                                                                               \
    {                                                                                                   \
    if (!(cond))                                                                                        \
        {                                                                                               \
        printf ("\nERROR in %s in line %d in function %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);  \
        }                                                                                               \
    }

/**
* @brief Solves the equation
*
* @param [in] a a-coefficient
* @param [in] b b-coefficient
* @param [in] c c-coefficient
* @param [in] roots an array of roots
* @param [out] x1 Pointer to 1st root
* @param [out] x2 Pointer to 2nd root
*
* @return number of roots
*/
int solveEquation(double a, double b, double c, double *roots);

/**
* @brief Gets the coefficients
*
* @param [out] a a-coefficient
* @param [out] b b-coefficient
* @param [out] c c-coefficient
*/
void inPut(double *a, double *b, double *c);

/**
* @brief Prints the roots
*
* @param [in] nRoots number of roots
*/
void ansOut(int nRoots, double *roots);

/**
* @brief Changes the number of roots to words
*/
enum changeNum {ALL_REAL_NUMBERS = -1,
                ZERO_SOL = 0,
                ONE_SOL,
                TWO_SOL};

#endif
