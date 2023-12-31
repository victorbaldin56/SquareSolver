#include <math.h>
#include <assert.h>
#include "solver.h"
 
/**
 * 
*/
static int do_solve_linear(Polynome *eq);

bool isequal(double a, double b) {
    const double prec = 1.0e-7; // точность сравнения
    return (fabs(a - b) <= prec) || (isnan(a) && isnan(b));
}


int solve_square(Polynome *eq) {

    assert(isfinite(eq->a));
    assert(isfinite(eq->b));
    assert(isfinite(eq->c));

    if (isequal(eq->a, 0)) {
        assert(eq != NULL);

        int nroots = do_solve_linear(eq);
        return nroots;
    }

    if (isequal(eq->c, 0)) {
        
        if (!isequal(eq->b, 0)) {
            eq->x2 = 0;
            Polynome lin_equation = {};
            Polynome *leq = &lin_equation;
            leq->c = eq->b;
            leq->b = eq->a;
            leq->a = 0;
            do_solve_linear(leq);
            eq->x1 = leq->x1;
            // Doc or back coefs
            return 2;
        }

        else {
            eq->x1 = 0;
            return 1;
        }

    }

    else {
        double D = eq->b * eq->b - 4 * eq->a * eq->c;

        if (isequal(D, 0)) {
            eq->x1 = -eq->b / (2 * eq->a);
            return 1;
        }

        else {
            
            if (D > 0) {
                double sqrt_D = sqrt(D);
                eq->x1 = (-eq->b - sqrt_D) / (2 * eq->a);
                eq->x2 = (-eq->b + sqrt_D) / (2 * eq->a);

                return 2;
            }

            else {
                return 0;
            }

        }
        
    }

}

static int do_solve_linear(Polynome *eq) {

    assert(isfinite(eq->b));
    assert(isfinite(eq->c));

    if (isequal(eq->b, 0)) {
        
        if (isequal(eq->c, 0)) {
            return SS_INF_ROOTS;
        }

        else {
            return 0;
        }

    }

    else {
        eq->x1 = -eq->c / eq->b;
        return 1;
    }
}
