#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "solver.h"

int solve_test() {
    FILE *fp = fopen("test_values.csv", "r"); // чтение файла с тестовыми значениями
    double a = NAN, b = NAN, c = NAN;
    double roots[2] = {NAN, NAN};                  // массив корней, который заполняется функцией solve
    double valid_roots[2] = {NAN, NAN};            // конрольные значения корней, полученные из файла
    int ans = 0;                              // возвращаемое значение функции solve
    int valid_ans = 0;                        // контрольное значение функции solve
    int res = 0;                              // результат тестирования

    while (!feof(fp)) {
        int n_arg = fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%d", 
                &a, &b, &c, &valid_roots[0], &valid_roots[1], &valid_ans);
        if (n_arg != 6 && n_arg != EOF) {
            printf("Invalid test values\n");
            return -1;
        }
        else {
            ans = solve(roots, a, b, c);
            if (ans == valid_ans &&
                    is_equal(roots[0], valid_roots[0]) && is_equal(roots[1], valid_roots[1])) {
                printf("OK\n");
                continue;
            }
            else {
                printf("Test failed on values: a = %g, b = %g, c = %g\n",
                                               a, b, c);
                res = -1;
            }
        }
    }
    
    if (res == 0)
        printf("Tests OK\n");

    fclose(fp);
    return res;
}