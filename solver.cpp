#include <math.h>
#include <stdio.h>
#include "solver.h"

int solver(double roots[], double a, double b, double c) {
    double D;
    
    D = b * b - 4 * a * c;
    if (a != 0) {
        if (D >= 0) {
            roots[0] = (-b - sqrt(D)) / (2 * a);
            roots[1] = (-b + sqrt(D)) / (2 * a);
            return NORMAL;
        }
        else {
            return NOSOL;
        }
    }
    else {
        return NOTSQUARE;
    }
}