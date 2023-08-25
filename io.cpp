#include <stdio.h>
#include <assert.h>
#include "solver.h"
#include "colors.h"

static void clear_buf();

void input_coeffs(Polynome *eq) {
    assert(eq != NULL);
    printf("Enter a, b, c: ");

    while (scanf("%lf %lf %lf", &eq->a, &eq->b, &eq->c) != 3) { // EOF?
        clear_buf();
        printf(FG_RED);
        printf("Wrong input, try again\n"); // retry
        printf(RESET);
    }
    
}

void print_roots(Polynome *eq) {
    assert(eq != NULL);

    switch (solve_square(eq)) {
        case 0:
            printf("No roots\n");
            break;
        case 1:
            printf("Root: %g\n", eq->x1);
            break;
        case 2:
            printf("Roots: %g %g\n", eq->x1, eq->x2);
            break;
        case SS_INF_ROOTS:
            printf("Infinte number of roots\n");
            break;
        default:
            printf("Error: unknown case\n");
    }

}

static void clear_buf() {
    int c = 0;
    while (c != '\n') {
        c = getchar();
    }
}
