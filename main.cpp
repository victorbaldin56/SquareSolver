#include <stdio.h>
#include "solver.h"

int solver(double[], double, double, double);

int main() {
    double a, b, c;
    double roots[2];
    
    printf("Enter equation coeffitients: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    switch(solver(roots, a, b, c)) {
        case NORMAL:
            if (roots[0] != roots[1])
                printf("%g %g\n", roots[0], roots[1]);
            else
                printf("%g\n", roots[0]);
            break;
        case NOSOL:
            printf("Error: no solution in real numbers\n");
            break;
        case NOTSQUARE:
            printf("Error: not square equation\n");
            break;
    }
    return 0;
}