#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "solver.h"

const int MAXLEN = 10000; // max lenght of compared strings

int main(int argc, char *argv[]) {
    printf("# Square equation solver\n"
           "# (c) Victor Baldin, 2023\n");
    
    #ifndef NDEBUG
    if (argc == 3 && !strncmp("--test", argv[1], MAXLEN)) { 
        // run tests
        printf("# Running test\n");
        FILE *test_file = fopen(argv[2], "r");
        if(!test_file) {
            perror("fopen() failed"); // Why
        }
        assert(test_file != NULL);
        return ss_test(test_file);
    }
    #endif // NDEBUG

    if (argc == 2 && !strncmp("--help", argv[1], MAXLEN)) {
        printf("Usage: ./square_solver [opions]\n"
               "Options:\n");
        return 0;
    }

    Polynome equation = {};

    if (!input_coeffs(&equation)) {
        print_roots(&equation);
    }
    else {
        putchar('\n');
    }

    return 0;
}
