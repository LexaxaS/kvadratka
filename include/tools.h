//! @file

/*************************************************
* Functions that are not about solving an equation
*
* @see bufClear
* @see isZero
* @see areEqual
*
**************************************************/

#ifndef TOOLS_H
#define TOOLS_H

/**
* @brief Absolute tolerance
*/
const double AT = 1e-6;

/**
* @brief clears buffer
*/
void bufClear(void);

/**
* @brief Checks if number is zero
*
* @param [in] x Number
*
* @return True if number is zero, False if not
*/
bool isZero(double x);

/**
* @brief Checks if numbers are equal
*
* @param [in] a first number
* @param [in] b second number
*
* @return True if numbers are equal, False if not
*/
bool areEqual(double a, double b);

#endif
