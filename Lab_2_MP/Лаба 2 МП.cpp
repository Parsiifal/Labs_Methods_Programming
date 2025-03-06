#include <iostream>
#include <cmath>
using namespace std;


float check_floatX(int min, int max, string strngln) 
{
	float x;
	cout << strngln << "\n";
	cin >> x;
	while (cin.fail() || cin.peek() != '\n' || x < min || x > max)
	{
		//cin.fail() проверяет состояние failbit и в случае его обнаружения возвращает true;
		//cin.peek() возвращает целочисленное представление следующего символа в буфере потока, не прочитав его;
		// (cin.peek() != '\n') - символ, следующий за последным прочитанным, не является '\n'(строка не закончилась);
		cout << "\nВведите такое значение x, что -1 <= x <= 1 !\n" << endl;
		cin.clear();   // очищает все биты и устанавливает бит по умолчанию (std::ios_base::goodbit), таким образом приведя поток в рабочее состояние;
		cin.ignore(10000, '\n'); // очищаем буфер обмена
		cin >> x;
	}
	return x;
}


double check_doubleA(int min, string strngln)
{
	double x;
	cout << strngln << "\n";
	cin >> x;
	while (cin.fail() || cin.peek() != '\n' || x < min)
	{
		cout << "\nВведите корректное значение!\n" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> x;
	}
	return x;
}


int main()
{
	setlocale(LC_ALL, "ru");
	char ans;
	
	do		// зацикливаем программу;
	{
		float x = check_floatX(-1, 1, "\nВведите параметр x: ");	// вводим x

		double a = check_doubleA(0, "\nВведите a: ");	// вводим a

		if (a == (int)a)	// если а - целое, то запускается тело if, а если а - дробное, то тело else;
		{
			a = (int)a;
			cout << "\nПараметр a - число итераций!" << endl;
			double sum = 0;

			for (int n = 0; n < a; n++)		// цикл, выполняющий столько итераций, какое значение принимает а;
			{

				double f;
				f = (pow(-1, n) * pow(x, 2 * n + 1) * (1 + pow(x, 2))) / (2 * n + 1);

				cout << "\nНомер итерации: " << n + 1 << "        ";

				cout << "Последний просумированный член ряда: " << f << "        ";

				sum = sum + f;
				cout << "Текущая частичная сумма: " << sum << "        ";

				// Цикл для вычисления и вывода точности вычисления;
				for (int j = n + 1; j < n + 2; j++)
				{
					double f1;
					f1 = (pow(-1, j) * pow(x, 2 * j + 1) * (1 + pow(x, 2))) / (2 * j + 1);

					double accuracy;
					accuracy = fabs(f1 / sum);

					cout << "Точность вычисления текущей частичной суммы: " << accuracy << endl;

				}

			}

			cout << "\nЕсли хотите повторить программу, нажмите y! Принажатии другой клавиши программа завершится!\n";
			cin >> ans;

		}
		else
		{
			cout << "\nПараметр a - точность!" << endl;;
			double sum = 0;
			double accuracy;
			int n = 0;
			do			// цикл, выполняющийся до достижения определенной точности a;
			{

				double f;
				f = (pow(-1, n) * pow(x, 2 * n + 1) * (1 + pow(x, 2))) / (2 * n + 1);

				cout << "\nНомер итерации: " << n + 1 << "        ";

				cout << "Последний просумированный член ряда: " << f << "        ";

				sum = sum + f;
				cout << "Текущая частичная сумма: " << sum << "        ";

				// Вычисление и вывод точности вычисления;
				int j = n + 1;
				double f1;
				f1 = (pow(-1, j) * pow(x, 2 * j + 1) * (1 + pow(x, 2))) / (2 * j + 1);

				accuracy = fabs(f1 / sum);
				cout << "Точность вычисления текущей частичной суммы: " << accuracy << endl;

				n++;

			} while (a < accuracy);

			cout << "\nЕсли хотите повторить программу, нажмите y! При нажатии другой клавиши программа завершится!\n";
			cin >> ans;

		}

	} while (ans == 'y');

}