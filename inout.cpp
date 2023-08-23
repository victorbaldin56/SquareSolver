#include <stdio.h>
#include "solver.h"

void clear_buf() {
    int c = 0;
    while (c != '\n') {
        c = getchar();
    }
}

void input_coeffs(double* a, double* b, double* c) {
    printf("Enter a, b, c: ");

    while(scanf("%lf %lf %lf", a, b, c) != 3) { // EOF?
        clear_buf();
        printf("Wrong input, try again\n"); // retry
    }

}

void print_roots(double roots[], const double a, const double b, const double c) {
    
    switch (solve_square(roots, a, b, c)) {
        case 0:
            printf("No roots");
            break;
        case 1:
            printf("Root: %g\n", roots[0]);
            break;
        case 2:
            printf("Roots: %g %g\n", roots[0], roots[1]);
            break;
        case INFINITE:
            printf("Infinte number of roots\n");
            break;
        default:
            printf("Error: unknown case\n");
    }

}