﻿#include <iostream>
#include <cmath>

using namespace std;

float a = 0;

float check_float1(float min, float max, string strngln) // функция для проверки ввода а - катета
{
	float x;
	cout << strngln << "\n";
	cin >> x;
	while (cin.fail() || cin.peek() != '\n' || x < min || x > max) 
	{
		//cin.fail() проверяет состояние failbit и в случае его обнаружения возвращает true
		//cin.peek() возвращает целочисленное представление следующего символа в буфере потока, не прочитав его
		// (cin.peek() != '\n') - символ, следующий за последным прочитанным, не является '\n'(строка не закончилась)
		cout << "Введите корректное значение!\n" << endl;
		cin.clear(); //cin.clear() очистит все биты и установит бит по умолчанию (std::ios_base::goodbit), таким образом приведя поток в рабочее состояние.
		cin.ignore(10000, '\n'); // очищаем буфер обмена путем игнорирования большого числа символов
		cin >> x;
	}
	return x;
}

float check_float(float min, float max, string strngln) // функция для проверки ввода b - гипотенузы
{
	float x;
	cout << strngln << "\n";
	cin >> x;
	while (cin.fail() || cin.peek() != '\n' || x < min || x > max || x < a)
	{
		cout << "Введите корректное значение!\n" << endl;
		cin.clear(); // очищаем ошибку cin
		cin.ignore(10000, '\n'); // очищаем буфер обмена
		cin >> x;
	}
	return x;
}

int main() {

	setlocale(LC_ALL, "Russian");

	char ans;
	do {	// зацикливаем код для повторной работы программы;

		a = check_float1(0.0000001, 1000000, "\nВведите длину катета прямоугольного треугольника в сантиметрах: \n" ); // вводим значение а - катета и проверяем на ввод

		float b = check_float(0.0000001, 1000000, "\nВведите длину гипотенузы прямоугольного треугольника в сантиметрах: \n"); // вводим значение b - гипотенузы и проверяем на ввод
		

		int i = 2; // переменная i - степень, в которую по теореме Пифагора мы будем возводить a и b;

		a = pow(a, i);	// возведение a и b во вторую степень;
		b = pow(b, i);

		float c = b - a;	//	вычисление значения искомого катета в квадрате;
		cout << "\n" << "Искомый катет прямоугольного треугольника равен: " << sqrt(c) << "\n\n";
		//	вывод в консоль длины искомого катета с извлечением корня из c;
		cout << "\nХотите повторить программу? Нажмите y:\n";
		cin >> ans;

	} while (ans == 'y');

}