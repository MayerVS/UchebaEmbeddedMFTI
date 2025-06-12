#pragma once

#include <math.h>

// Тут храняться все расчетные функции

double root(double f(double), double g(double), double a, double b, double eps, int *stepcount); // Нахождение корня
double integral(double f(double), double a, double b, double eps); // Расчет интеграла