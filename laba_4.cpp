#include <iostream>
using namespace std;

//--- Вычисление значения функции cos через степенной ряд
double cos_rec(double x) { 
    double s = 0., sn = 1, eps = 0.00001;
    for (int n = 1; fabs(sn) > eps; n++) {
        s += sn;
        sn *= -x * x / (2.0 * n - 1.0) / (2.0 * n);
    }
    return s;
}

//--- Вычисление значения функции (x^2) - (pi^2) / 3) / 4 через степенной ряд
double sum(double x, double eps, int& n) { // -cos(x) + cos(2x) / 2**2 - cos(3x) / 3**2 + … + (-1)**n*cos(nx) / n**2
    double s = 0., sn = -cos_rec(x);
    for (n = 2; fabs(sn) > eps; n++) {
        s += sn;
        sn = ((pow(-1, n) * cos_rec(n * x)) / (n * n));
    }
    return s;
}

// Вычисление степенного ряда для x в диапазоне от 0.1 до 1 с шагом 0.1
int main() {
    double y, y_rec, pi = 3.14159265359;
    int nn;
    for (double x = 0.1; x <= 1; x += 0.1) {
        y = ((x * x) - (pi * pi) / 3) / 4;
        y_rec = sum(x, 0.0001, nn);
        printf("n=%d x=%0.1lf\t sum=%0.4lf\t function=%0.4lf\n", nn, x, y_rec, y);
    }
    return 0;
}