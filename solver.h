#ifndef MY_SOLVER_H
#define MY_SOLVER_H 1

const int INFINITE = 3; // бесконечное число корней
const int ERROR = -1; // ошибка


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

int solve_test();

#endif // MY_SOLVER_H