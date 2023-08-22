#ifndef MY_SOLVER_H
#define MY_SOLVER_H 1

enum roots_num {
    NO,
    SINGLE,
    TWO,
    INFINITE,
    ERR = -1, 
};

roots_num solve(double roots[], const double a, const double b, const double c);
bool isequal(double a, double b);
int solve_test();

#endif // MY_SOLVER_H