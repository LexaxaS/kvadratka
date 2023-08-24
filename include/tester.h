//! @file

/***************************
* Tests the system
*
* @see tester
***************************/

#ifndef TESTER_H
#define TESTER_H

/**
* @brief Tests the program
*
* @param [in] filename name of the file with tests
*
* @note You can enter the filename in the argument of cmd
*/
void tester(char *filename);

/**
* @brief file length
*
* @note needed only to calculate the number of failed tests
*/
const int length = 4;

#endif
