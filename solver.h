#ifndef MY_SOLVER_H
#define MY_SOLVER_H

#include <stdio.h>

#define NDEBUG

const int SS_INF_ROOTS = 3;
const int ERROR = -1;

/**
 * Structure of coeffs and roots of the polynome
*/
typedef struct {
    double a, b, c; ///< This is coeffs
    double x1, x2;  ///< This is roots
} Polynome;

/**
 * Structure of reference values for test
*/
typedef struct {
    double a, b, c;        ///< This is quadratic equation coeffs
    double x1_ref, x2_ref; ///< This is reference values of roots
    int nroots_ref;        ///< This is reference value of number of roots
} TestData;

/**
 * Solves the quadratic equation a*x^2+b*x+c=0
 * @param eq pointer to a Polynome structure
 * @return number of roots of the polynome 
*/
int solve_square(Polynome *eq);

/**
 * Two doubles comparison
 * @param a
 * @param b
 * @return 1 if close enough, 0 if not  
*/
bool isequal(double a, double b);

/**
 * Tests solve_square until the end of test file
 * @param test_file pointer to the file with reference values
 * @return -1 in case of error, otherwise 0
*/

/**
 * @param eq pointer to a Polynome structure
 * Reads coefs from standart input
*/
int input_coeffs(Polynome *eq);

/**
 * @param eq pointer to a Polynome structure
*/
void print_roots(Polynome *eq);

int ss_test(FILE *test_file);

#endif // MY_SOLVER_H