#include <math.h>
#include <stdio.h>
#include "solver.h"

#define PREC 1.0e-10

// сравнение двух чисел типа double
static int isEqual(double a, double b) {
    return fabs(a - b) <= PREC;
}

roots_num solver(double roots[], double a, double b, double c) {
    double D;
    
    D = b * b - 4 * a * c;
    if (!isEqual(a, 0)) {
        if (D >= 0) {
            if (!isEqual(D, 0)) {
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
        if (!isEqual(b, 0)) {
            roots[0] = -c / b;
            return SINGLE;
        }
        else {
            if (!isEqual(c, 0)) {
                return NO;
            }
            else {
                return INFINITE;
            }
        }
    }
}