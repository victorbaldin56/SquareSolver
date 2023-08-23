#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "solver.h"

/**
 * Unit test for solve_square function
 * @param a first coef
 * @param b second coef
 * @param c third coef
 * @param roots_ref reference roots
 * @param nroots_ref reference return value of solve_square()
 * @return 0 if all values are equal to the reference, -1 if not
*/
static int check(double a, double b, double c, double roots_ref[], int nroots_ref);

int solve_test(FILE *test_file) {

    double a = NAN, b = NAN, c = NAN;
    double roots_ref[2] = {NAN, NAN}; 
    int nroots_ref = 0;
    int test_res = 0;
    fscanf(test_file, "a,b,c,root1,root2,ans");           // проверка на наличие пояснений в test_file
    while (!feof(test_file)) {
        int n_arg = fscanf(test_file, "%lf, %lf, %lf, %lf, %lf, %d",
                                &a, &b, &c, &roots_ref[0], &roots_ref[1], &nroots_ref);  
        if (n_arg != 6 && n_arg != EOF) {
            printf("wrong input in test file\n");
            return -1;
        };
        if (check(a, b, c, roots_ref, nroots_ref) == -1)
            test_res = -1;                        

    }
    if (test_res == 0)
        printf("Test OK\n");
    return test_res;

}

static int check(double a, double b, double c, double roots_ref[], int nroots_ref) {
    double roots[] = {NAN, NAN};
    int nroots = solve_square(roots, a, b, c);
    if (!is_equal(roots[0], roots_ref[0]) || !is_equal(roots[1], roots_ref[1]) || 
                  nroots != nroots_ref) {
        printf("TEST FAILED: a = %g, b = %g, c = %g\n"
                "Roots: %g, %g, number of roots: %d\n"
                "Expected: %g, %g, %d",
                a, b, c, roots[0], roots[1], nroots, 
                roots_ref[0], roots_ref[1], nroots_ref);
        return -1;
    }
    else {
        return 0;
    }
}