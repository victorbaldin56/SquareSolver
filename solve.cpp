#include <math.h>
#include <cassert>
#include "solver.h"

// сравнение двух чисел типа double
bool isequal(double a, double b) {
    const double prec = 1.0e-7; // точность сравнения
    return (fabs(a - b) <= prec) || (isnan(a) && isnan(b));
}

/**
 * Case of linear equation b*x+c=0
 * @param roots array of roots
 * @param b first coef
 * @param c second coef
 * @return the number of roots or error code -1
*/
static int solve_linear(double roots[], const double b, const double c) {
    if (!isequal(b, 0)) {
        roots[0] = -c / b;
        roots[1] = NAN;
        return 1;
    }
    else {
        if (!isequal(c, 0)) {
            roots[0] = roots[1] = NAN;
            return 0;
        }
        else {
            roots[0] = roots[1] = NAN;
            return INFINITE;
        }
    }
}

static int solve_quad(double roots[], const double a, const double b, const double c) {
    double D = b * b - 4 * a * c;
    if (!isequal(b, 0)) {
        if (D >= 0) {
            if (!isequal(D, 0)) {
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
    else {
        // оптимизация для случая нулевого свободного коэффициента
        if (!isequal(b, 0)) {
            solve_linear(roots, a, b);
            roots[1] = 0;
            return 2;
        }
        else {
            roots[0] = 0;
            return 1;
        }
    }
}

int solve(double roots[], double a, double b, double c) {
    if (!isfinite(a) || !isfinite(b) || !isfinite(c))
        return -1;
    if (roots == NULL)
        return -1;

    if (!isequal(a, 0))
        return solve_quad(roots, a, b, c);
    else
        return solve_linear(roots, b, c);
}