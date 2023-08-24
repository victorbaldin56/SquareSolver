#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cassert>
#include "solver.h"

const int MAXLEN = 1000; // max lenght of compared strings

int main(int argc, char *argv[]) {
    printf("# Square equation solver\n"
           "# (c) Victor Baldin, 2023\n");
    
    if (argc == 3 && !strncmp("--test", argv[1], MAXLEN)) { // key --help , --test filename 
        // run tests
        printf("# Running test\n");
        FILE *test_file = fopen(argv[2], "r");
        assert(test_file != NULL);
        return ss_test(test_file);
    }

    if (argc == 2 && !strncmp("--help", argv[1], MAXLEN)) {
        printf("square_solver solves the quadratic equation ax^2 + bx + c, "
               "where a, b, c is real numbers\n"
               "Run ./square_solver and enter coeffitients a, b, c in format \"a b c\"\n");
        return 0;
    }

    Polynome equation;
    Polynome *eq = &equation;

    assert(eq != NULL);
    input_coeffs(eq);
    print_roots(eq);

    return 0;
}