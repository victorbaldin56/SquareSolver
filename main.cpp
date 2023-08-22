#include <stdio.h>
#include <math.h>
#include <string.h>
#include "solver.h"

int main(int argc, char *argv[]) {
    printf("# Square equation solver\n"
           "# (c) Victor Baldin, 2023\n");
    
    if (argc == 2 && !strcmp("test", argv[1])) {
        // запуск в режиме тестирования
        printf("# Running test\n");
        return solve_test();
    }

    double a = NAN, b = NAN, c = NAN;
    printf("# Enter equation coeffitients dividing by spaces: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Input error\n");
        return -1;
    }

    double roots[2] = {NAN};
    switch(solve(roots, a, b, c)) {
        case 2:
            printf("Roots: %g %g\n", roots[0], roots[1]);
            break;
        case 1:
            printf("Root: %g %g\n", roots[0], roots[1]);
            break;
        case INFINITE:
            printf("Infinite number of roots\n");
            break;
        case 0:
            printf("No roots\n");
            break;
        default:
            printf("Error: unknown case\n");
            return -1;
    }
    return 0;
}