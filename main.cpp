#include <stdio.h>
#include <math.h>
#include <string.h>
#include "solver.h"

int main(int argc, char *argv[]) {
    if (argc == 2 && !strcmp("test", argv[1])) {
        // запуск в режиме тестирования
        printf("# solve() test");
        return solve_test();
    }
    printf("# Square equation solver\n"
    "# (c) Victor Baldin, 2023\n");

    double a = NAN, b = NAN, c = NAN;
    printf("# Enter equation coeffitients dividing by spaces: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double roots[2] = {NAN};
    switch(solve(roots, a, b, c)) {
        case TWO:
            printf("Roots: %lf %lf\n", roots[0], roots[1]);
            break;
        case SINGLE:
            printf("Root: %lf\n", roots[0]);
            break;
        case INFINITE:
            printf("Infinite number of roots\n");
            break;
        case NO:
            printf("No roots\n");
            break;
        case ERR:
            printf("Error: invalid arguments\n");
            return -1;
        default:
            printf("Error: unknown case\n");
            return -1;
    }
    return 0;
}