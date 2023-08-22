#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "solver.h"

#define SUCCESS "OK" // тест пройден
#define FAIL "FAILED" // тест не пройден

#define MAXLEN 1000 // максимальная длина операнда

// функция считывания значений из файла
static void parse_csv(FILE *fp) {
    
}

int solve_test() {
    FILE *fp = fopen("test_values.csv", "r"); // чтение файла с тестовыми значениями
    double a = NAN, b = NAN, c = NAN;
    double roots[2] = {NAN}; // массив корней, который заполняется функцией solve
    double test_roots[2] = {NAN}; // конрольные значения корней, полученные из файла
    int ans = 0; // возвращаемое значение функции solve
    int test_ans = 0; // контрольное значение функции solve
    int res = 0; // результат тестирования

    while (!feof(fp)) {
        int c = fgetc(fp);
        
    }

    fclose(fp);
    return res;
}