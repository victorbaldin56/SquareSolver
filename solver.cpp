#include <math.h>
#include "solver.h"

#define PREC 1.0e-10 // точность сравнения

// сравнение двух чисел типа double
static bool isequal(double a, double b) {
    return fabs(a - b) <= PREC;
}

roots_num solver(double roots[], double a, double b, double c) {
    double D = 0;
    
    if (roots == NULL || isnan(a) || isnan(b) || isnan(c))
        return ERR;
    D = b * b - 4 * a * c;
    if (!isequal(a, 0)) {
        if (D >= 0) {
            if (!isequal(D, 0)) {
                roots[0] = (-b - sqrt(D)) / (2 * a);
                roots[1] = (-b + sqrt(D)) / (2 * a);
                return TWO;
            }
            else {
                roots[0] = -b / (2 * a);
                return SINGLE;
            }
        }
        else {
            return NO;
        }
    }
    else {
        if (!isequal(b, 0)) {
            roots[0] = -c / b;
            return SINGLE;
        }
        else {
            if (!isequal(c, 0)) {
                return NO;
            }
            else {
                return INFINITE;
            }
        }
    }
}