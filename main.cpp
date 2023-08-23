#include <stdio.h>
#include <math.h>
#include <string.h>
#include "solver.h"

const int MAXLEN = 1000; // max lenght of compared strings

// clears input buffer
static void clear_buf();

int main(int argc, char *argv[]) {
    printf("# Square equation solver\n"
           "# (c) Victor Baldin, 2023\n");
    
    if (argc == 2 && !strncmp("--test", argv[1], MAXLEN)) {
        // запуск в режиме тестирования
        printf("# Running test\n");
        FILE *test_file = fopen("test_values.csv", "r");
        return solve_test(test_file);
    }

    double a = NAN, b = NAN, c = NAN;
    printf("# Enter equation coeffitients dividing by spaces: ");
    
    while(scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        clear_buf();
        printf("Wrong input, try again\n"); // retry
    }

    double roots[2] = {NAN, NAN};
    switch(solve_square(roots, a, b, c)) {
        case 2:
            printf("Roots: %g %g\n", roots[0], roots[1]);
            break;
        case 1:
            printf("Root: %g\n", roots[0]);
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

static void clear_buf() {
    int c = 0;
    while (c != '\n') {
        c = getchar();
    }
}