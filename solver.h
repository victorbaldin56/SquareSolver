#ifndef MY_SOLVER_H
#define MY_SOLVER_H 1

#include <stdio.h>

const int SS_INF_ROOTS = 3; // бесконечное число корней
const int ERROR = -1;

/**
 * 
*/
typedef struct {
    double a, b, c;
    double x1, x2;
} Polynome;

/**
 * 
*/
typedef struct {
    double a, b, c;
    double x1_ref, x2_ref;
    int nroots_ref;
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
int ss_test(FILE *test_file);

/**
 * @param a pointer to a
 * @param b pointer to b
 * @param c pointer to c
*/
void input_coeffs(Polynome *eq);

/**
 * 
*/
void print_roots(Polynome *eq);

#endif // MY_SOLVER_H