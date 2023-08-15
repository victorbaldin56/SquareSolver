#include <stdio.h>

double root1, root2;
double a, b, c; // коэффициенты квадратного уравнения
int solver(double, double, double);

int main() {
    printf("Enter equation coeffitients: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    switch(solver(a, b, c)) {
        case 0:
            if (root1 != root2)
                printf("%g %g\n", root1, root2);
            else
                printf("%g\n", root1);
            break;
        case 1:
            printf("Error: no solution in real numbers\n");
            break;
        case 2:
            printf("Error: not square equation\n");
            break;
    }
    return 0;
}