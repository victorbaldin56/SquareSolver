#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "solver.h"
#include "colors.h"

/**
 * Unit test for solve_square function
 * @param num Number of current test
 * @param data The structure contains test reference data
*/
static int run_test(int num, TestData *data);

int ss_test(FILE *test_file) {
    int test_res = 0;
    int num = 0; // test number
    int succeed = 0; // number of succeed tests

    TestData test_data = {};
    TestData *data = &test_data;

    fscanf(test_file, "a,b,c,root1,root2,ans");
    
    while (!feof(test_file)) {
        int n_arg = fscanf(test_file, 
            "%lf, %lf, %lf, %lf, %lf, %d",
            &(data->a), &(data->b), &(data->c), 
            &(data->x1_ref), &(data->x2_ref), &(data->nroots_ref)); //\n in end of file
        
        if (n_arg == EOF) {
            break;
        }

        if (n_arg != 6) {
            printf("wrong input in test file\n");
            return -1;
        };
        
        num++;
        
        assert(data != NULL);

        if (run_test(num, data) == -1) {
            test_res = -1; 
        }
        else {
            succeed++;
        }                        
    }
    
    if (succeed == num) {
        printf(FG_GREEN);
    }
    else {
        printf(FG_RED);
    }

    printf("%d/%d tests succeed\n", succeed, num);

    return test_res;
}

static int run_test(int num, TestData *data) {
    Polynome quad_equation = {};
    Polynome *eq = &quad_equation;

    eq->a = data->a;
    eq->b = data->b;
    eq->c = data->c;
    eq->x1 = eq->x2 = NAN;

    int nroots = solve_square(eq);

    if (!isequal(eq->x1, data->x1_ref) || 
        !isequal(eq->x2, data->x2_ref) || 
                    nroots != data->nroots_ref) {
        printf(FG_RED);
        printf("TEST %d FAILED: "
               "a = %g, b = %g, c = %g\n"
               "Received: %g, %g, %d\n" 
               "Expected: %g, %g, %d\n",
                num, 
                data->a, data->b, data->c,
                eq->x1, eq->x2, nroots,
                data->x1_ref, data->x2_ref, data->nroots_ref);
        return -1;
    }
    else {
        return 0;
    }
}