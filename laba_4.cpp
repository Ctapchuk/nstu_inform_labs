#include <iostream>
using namespace std;

//--- Вычисление значения функции cos через степенной ряд (взято из стороннего источника)
double cos_rec2(double x) {
    double s = 0., sn = 1, eps = 0.00001;
    for (int n = 1; fabs(sn) > eps; n++) {
        s += sn; // сумма значений
        sn *= -x * x / (2.0 * n - 1.0) / (2.0 * n); // рекурентая формула
    }
    return s;
}

//--- Та же что и ниже, но используя рекурсивную функцию
double cos_recfun(double x, int n) {
    if (n == 0)
        return 1;
    --n;
    return cos_recfun(x, n) * cos(x) - sin(n * x) * sin(x);
}

//--- Вычисление значения функции cos через степенной ряд (используя формулу с cprog)
double cos_reс(double x, int n) {
    double sn = 1;
    while (n >= 1) {
        sn *= cos(n * x) / cos(x * (n - 1));
        --n;
    }
    return sn;
}

//--- Вычисление значения функции (x^2) - (pi^2) / 3) / 4 через степенной ряд
double sum(double x, double eps, int& n) {
    double s = 0., sn = -cos_reс(x, 1); // первый член 
    for (n = 2; fabs(sn) > eps; n++) { // цикл по вычислению ряда, начинаем с 2-ух (первый шаг прописан выше вручную); продолжаем цикл до достижения точности eps (до какой цифры после запятой уточнять значение)
        s += sn; // сумма значений
        sn *= -pow((-1 + n), 2) * cos_reс(x, n) / (pow(n, 2) * cos_reс(x, n - 1));
    }
    return s;
}

// Вычисление степенного ряда для x в диапазоне от 0.1 до 1 с шагом 0.1
int main() {
    double y, y_rec, pi = 3.14159265359;
    int nn;
    for (double x = 0.1; x <= 1; x += 0.1) {
        y = ((x * x) - (pi * pi) / 3) / 4; // вычисление оригинальной функции
        y_rec = sum(x, 0.0001, nn); // вычисление приблизительного значения функции с помощью ряда Тейлора; передаём сам x, eps (отвечает за точность вычисления) и ссылку на переменнаую для вывода кол-ва шагов
        printf("n=%d x=%0.1lf\t sum=%0.4lf\t function=%0.4lf\n", nn, x, y_rec, y);
    }
    return 0;
}