#include <stdio.h>
#include <math.h>
#include "solver.h"

#define SUCCESS "OK" // тест пройден
#define FAIL "FAILED" // тест не пройден

int test() {
    FILE *fp = fopen("test_values.csv", "r"); // чтение файла с тестовыми значениями
    double a = NAN, b = NAN, c = NAN;
    double test_roots[2] = {NAN}, roots[2] = {NAN};
    int test_ans = 0; // правильное число корней, которое должна вернуть функция solve
    int ans = 0; // возращаемый результат
    int test_no = 0; // номер теста
    int res = 0; // результат теста
    printf("Test\tStatus\n");
    
    while (fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%d", &a, &b, &c, &test_roots[0], &test_roots[1], &test_ans) == 6) {
        ans = solve(roots, a, b, c);
        test_no++;
        if (test_ans == ans) {
            if (isequal(roots[0], test_roots[0]) && isequal(roots[1], test_roots[1])) {
                printf("%4d\t%6s\n", test_no, SUCCESS);
            }
            else {
                printf("%4d\t%6s\n", test_no, FAIL);
                res = -1;
            }
        }
    }
    
    fclose(fp);
    return res;
}