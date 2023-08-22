#ifndef MY_SOLVER_H
#define MY_SOLVER_H 1

const int INFINITE = 3; // бесконечное число корней

int solve(double roots[], const double a, const double b, const double c);
bool isequal(double a, double b);
int solve_test();

#endif // MY_SOLVER_H