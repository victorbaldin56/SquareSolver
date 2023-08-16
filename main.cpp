#include <stdio.h>
#include "solver.h"

int main() {
    double a, b, c;
    double roots[2];

    a = b = c = 0;
    printf("Enter equation coeffitients: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    switch(solver(roots, a, b, c)) {
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