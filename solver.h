#ifndef MY_SOLVER_H
#define MY_SOLVER_H 1

#include <stdio.h>

const int INFINITE = 3; // бесконечное число корней
const int ERROR = -1;

/**
 * Solves the quadratic equation a*x^2+b*x+c=0
 * @param roots array of roots filled by this function
 * @param a first coef
 * @param b second coef
 * @param c third coef
 * @return the number of roots or error code -1 
*/
int solve_square(double roots[], const double a, const double b, const double c);

/**
 * Two doubles comparison
 * @param a
 * @param b
 * @return 1 if close enough, 0 if not  
*/
bool is_equal(double a, double b);

/**
 * Tests solve_square until the end of test file
 * @param test_file pointer to the file with reference values
 * @return -1 in case of error, otherwise 0
*/
int ss_test(FILE *test_file);

/**
 * clears input buffer
*/

/**
 * 
*/
void input_coeffs(double* a, double* b, double* c);

/**
 * 
*/
void print_roots(double roots[], const double a, const double b, const double c);

#endif // MY_SOLVER_H