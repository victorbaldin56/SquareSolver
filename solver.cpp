#include <math.h>
#include <stdio.h>

int solver(double a, double b, double c) {
    extern double root1, root2;
    double D;
    
    D = b * b - 4 * a * c;
    if (a != 0) {
        if (D >= 0) {
            root1 = (-b - sqrt(D)) / (2 * a);
            root2 = (-b + sqrt(D)) / (2 * a);
            return 0; // решилось
        }
        else {
            return 1; // error -- no real solutions
        }
    }
    else {
        return 2; // error -- dividing by zero
    }
}