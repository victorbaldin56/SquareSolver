#include <stdio.h>
#include <math.h>
#include "solver.h"

int main() {
    double a = NAN, b = NAN, c = NAN;
    double roots[2];

    printf("Enter equation coeffitients dividing by spaces: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    switch(solve(roots, a, b, c)) {
        case TWO:
            printf("%g %g\n", roots[0], roots[1]);
            break;
        case SINGLE:
            printf("%g\n", roots[0]);
            break;
        case INFINITE:
            printf("Infinite number of roots\n");
            break;
        case NO:
            printf("No roots\n");
            break;
        case ERR:
            printf("Error: invalid arguments\n");
    }
    return 0;
}