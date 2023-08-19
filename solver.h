#ifndef MY_SOLVER_H
#define MY_SOLVER_H 1

enum roots_num {
    NO,
    SINGLE,
    TWO,
    INFINITE,
    ERR = -1, 
};

roots_num solve(double roots[], double a, double b, double c);
bool isequal(double a, double b);
int test();

#endif // MY_SOLVER_H