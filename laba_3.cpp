﻿#include <iostream>
#define  _CRT_SECURE_NO_WARNINGS
using namespace std;

int check_numbers(int& a, const int& n) { // функция для првоерки раразличности цифр в числе 
	int a1 = a, a2 = 0, n1 = 0, n2 = 0, b1 = 0, b2 = 0;
	while (n1 < n) { // внешний цикл по проверке цифр числа
		b1 = a1 % 10; // берём последнюю цифру числа для внешнего цикла 
		a2 = a1 /= 10; // организуем перебор цифр, отделяя от a1 последнюю цифру; берём копию a1 во внутренний цикл как a2
		if (n == 8 && b1 == 6 || b1 == 0) // дополнительная проверка на 6 и 0, т.к. их не должно быть в первом множителе по условию, выходим
			return -1;
		while (n2 < n - n1 - 1) { // внутренний цикл по проверки цифр числа; перебираем цифры числа a1 
			b2 = a2 % 10; // берём последнюю цифру числа для внутреннего цикла 
			a2 /= 10; // организуем перебор цифр, отделяя от a2 последнюю цифру
			if (b1 == b2)
				return -1; // одинаковые числа, выходим
			n2++;
		}
		n2 = 0; // обнуляем счётчик цифр для внутреннего цикла
		n1++; // +1 в счётчик внешнего цикла
	}
	return 0;
}

int check_conditionPro(int& a) { // функция для общей проверки условий задачи
	int a6 = 0, a6_2 = 0, i = 0; // a6 и a6_2 хранят значения a * 6, i используется для подсчёта цифр при проверке числа на разрядность 9
	const int n8 = 8; // 8-рязрядные числа
	const int n9 = 9; // 9-рязрядные числа

	if (check_numbers(a, n8) == -1) // проверка 8-рязрядных чисел на различие всех цифр
		return -1;

	a6 = a6_2 = a * 6; // произведение и его копии
	while (a6 != 0) { // проверка на разрядность 9
		a6 /= 10;
		++i;
	}

	if (i != n9) // если число не 9-разрядное, то выходим
		return -1;

	if (check_numbers(a6_2, n9) != -1) // финальная проверка на различность всех цифр в произведении
		return a6_2; // возвращаем произведение

	return -1; // возвращаем -1 в остальных случаях (нужно для Release сборок)
}

int main() {
	for (int a = 11111111, i = 0, w = 0; a < 100000000; a++) { // генерация чисел (первого множителя)
		w = check_conditionPro(a);
		if (w != -1) {
			printf("%d) %d ==========> %d\n", ++i, a, w); // i - номер выводимого числа, подходящего по условию; a - первый множитель, подходящий под условие; w - найденное произведение
		}
	}
	cout << "Took time: " << double(clock())/1000 << " sec" << endl;
}