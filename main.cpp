#include <stdio.h>
#include <math.h>
#include <string.h>
#include "solver.h"

int main(int argc, char *argv[]) {
    if (argc == 2 && !strcmp("test", argv[1])) {
        // запуск в режиме тестирования
        return test();
    }
    double a = NAN, b = NAN, c = NAN;
    printf("Enter equation coeffitients dividing by spaces: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double roots[2] = {NAN};
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
            return -1;
        default:
            printf("Error: unknown case\n");
            return -1;
    }
    return 0;
}