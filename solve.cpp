#include <math.h>
#include <cassert>
#include "solver.h"

// How many NaN exist

/**
 * Case of linear equation b*x+c=0
 * @param roots array of roots
 * @param b first coef
 * @param c second coef
 * @return the number of roots or error code -1
*/
static int do_solve_linear(double roots[], const double b, const double c);

/**
 * Case of quadratic equation
 * @param a first coef, a!=0
 * @param b second coef
 * @param c third coef
 * @return number of roots
*/
static int do_solve_quad(double roots[], const double a, const double b, const double c);

bool is_equal(double a, double b) {
    const double prec = 1.0e-7; // точность сравнения
    return (fabs(a - b) <= prec) || (isnan(a) && isnan(b));
}

int solve_square(double roots[], double a, double b, double c) {

    if (!isfinite(a) || !isfinite(b) || !isfinite(c))
        return ERROR;
    if (roots == NULL)
        return ERROR; 

    if (!is_equal(a, 0))
        return do_solve_quad(roots, a, b, c);
    else
        return do_solve_linear(roots, b, c);
}

static int do_solve_linear(double roots[], const double b, const double c) {

    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(roots != NULL);

    if (!is_equal(b, 0)) {
        roots[0] = -c / b;
        roots[1] = NAN;
        return 1;
    }
    else {
        if (!is_equal(c, 0)) {
            roots[0] = roots[1] = NAN;
            return 0;
        }
        else {
            roots[0] = roots[1] = NAN;
            return INFINITE;
        }
    }
}

static int do_solve_quad(double roots[], const double a, const double b, const double c) {
    
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(roots != NULL);

    double D = b * b - 4 * a * c;

    if (!is_equal(c, 0) && !is_equal(b, 0)) {
        if (D >= 0) {
            if (!is_equal(D, 0)) {
                double D1 = sqrt(D);
                roots[0] = (-b - D1) / (2 * a);
                roots[1] = (-b + D1) / (2 * a);
                return 2;
            }
            else {
                roots[0] = -b / (2 * a);
                roots[1] = NAN;
                return 1;
            }
        }
        else {
            roots[0] = roots[1] = NAN;
            return 0;
        }
    }

    else if (is_equal(b, 0) && !is_equal(c, 0)) {
        // оптимизация в случае нулевого второго коэффициента
        double root_sqr = -c / a;
        if (root_sqr > 0) {
            roots[0] = -sqrt(root_sqr);
            roots[1] = sqrt(root_sqr);
            return 2;
        }
        else {
            roots[0] = roots[1] = NAN;
            return 0;
        }
    }

    else {
        // оптимизация для случая нулевого свободного коэффициента
        if (!is_equal(b, 0)) {
            do_solve_linear(roots, a, b);
            roots[1] = 0;
            return 2;
        }
        else {
            roots[0] = 0;
            return 1;
        }
    }
}
