#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    char ans;
    setlocale(LC_ALL, "ru");

    do 
    {
        ifstream file; // создаем объект класса ifstream
        file.open("C:\\Users\\Artem1\\Desktop\\Файл лаба 4 МП читаем.txt"); // открываем файл для чтения

        // Проверка отрылся файл или нет
        if (file.is_open()) // вызов метода is_open()
            cout << "\nВсе хорошо! Файл открыт!" << endl;
        else
            cout << "\nФайл не открыт!\n" << endl;

        file.seekg(0, ios_base::end);   //становимся в конец файла 
        cout << "\nРазмер файла (в байтах): " << file.tellg() << endl; // считаем кол во символов

        int n = file.tellg(); // n - кол - во символов в файле  
        file.seekg(0, ios_base::beg);  // возвращаемся в начало файла
              
        // создаем буффер
        char* buffer = new char[n + 1];
        buffer[n] = 0;
        //читаем в него байты
        file.read(buffer, n);

        cout << "\nПрочитано из файла: " << buffer << endl;

        file.close();

        for (int i = 0; i < n; i++)  // заменяем все ' ' на *
        {
            if (buffer[i] == ' ')
                buffer[i] = '*';
        }

        vector <char> a;
        for (int i = 0; i < n; i++) // записываем в вектор эл ты буффера
            a.push_back(buffer[i]);
              
        auto last = unique(a.begin(), a.end()); // удаляем все, кроме первого *, из каждой последовательной группы * в диапазоне вектора
        a.erase(last, a.end()); // уменьшаем вектор до нового размера

        char* buffer2 = new char[a.size() + 1];
        buffer2[a.size()] = 0;

        for (int i = 0; i < a.size(); i++)  // записываем в буфер исправленный вектор
            buffer2[i] = a[i];
        
        cout << "\nЗаписано в файл: " << buffer2 << endl;

        ofstream file2; // файловый вывод
        file2.open("C:\\Users\\Artem1\\Desktop\\Файл лаба 4 МП записываем.txt"); // открываем файл для записи

        file2 << buffer2;
        delete[] buffer;
        delete[] buffer2;
        file2.close();

        cout << "\nДля повторения работы программы введите новые данные в файл, сохраните изменения, закройте файл, после чего введите y! В случае ввода другого символа программа завершится!\n";
        cin >> ans;

    } while (ans == 'y');

}