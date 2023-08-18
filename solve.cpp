#include <math.h>
#include "solver.h"

const double prec = 1.0e-10; // точность сравнения

// сравнение двух чисел типа double
static bool isequal(double a, double b) {
    return fabs(a - b) <= prec;
}

// решение для случая линейного уравнения
static roots_num solveLinear(double roots[], double b, double c) {
    if (!isequal(b, 0)) {
        roots[0] = -c / b;
        return SINGLE;
    }
    else {
        if (!isequal(c, 0))
            return NO;
        else
            return INFINITE;
    }
}

// решение для квадратного уравнения
static roots_num solveQuad(double roots[], double a, double b, double c) {
    double D = b * b - 4 * a * c;
    if (D >= 0) {
        if (!isequal(D, 0)) {
            double D1 = sqrt(D);
            roots[0] = (-b - D1) / (2 * a);
            roots[1] = (-b + D1) / (2 * a);
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

// ветвление на случаи и фиксация ошибок входных параметров
roots_num solve(double roots[], double a, double b, double c) {
    if (roots == NULL)
        return ERR;
    if (!isfinite(a) || !isfinite(b) || !isfinite(c))
        return ERR;
    if (!isequal(a, 0))
        return solveQuad(roots, a, b, c);
    else
        return solveLinear(roots, b, c);
}