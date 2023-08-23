#include <stdio.h>
#include <math.h>
#include <string.h>
#include "solver.h"

const int MAXLEN = 1000; // max lenght of compared strings

int main(int argc, char *argv[]) {
    printf("# Square equation solver\n"
           "# (c) Victor Baldin, 2023\n");
    
    if (argc == 2 && !strncmp("--test", argv[1], MAXLEN)) {
        // run tests
        printf("# Running test\n");
        FILE *test_file = fopen("test_values.csv", "r");
        return ss_test(test_file);
    }

    double a = NAN, b = NAN, c = NAN;
    input_coeffs(&a, &b, &c);
    double roots[2] = {NAN, NAN};
    print_roots(roots, a, b, c);

    return 0;
}