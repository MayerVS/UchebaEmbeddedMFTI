#include "func.h"

double root(double f(double), double g(double), double a, double b, double eps, int *stepcount)
{
    double x, minx = a, nextstep;
    nextstep = fabs(b - a) / (1 / eps); 
    *stepcount = 0;
    for (x = a; x < b; x += nextstep, (*stepcount)++)
    {
        if (fabs(f(x) - g(x)) < fabs(f(minx) - g(minx)))
            minx = x;
    }
    return minx;
}

double integral(double f(double), double a, double b, double eps)
{
    double sum = 0;
    double h = (b - a) / eps;
    for (double x = a + h; x < b - h; x += h)
        sum += 0.5 * h * (f(x) + f(x + h));
    return sum;
}
