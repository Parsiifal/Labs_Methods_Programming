#include <iostream>
#include <string>
#include <vector>
using namespace std;


int check_input(int min)
{
    int res;
    string inp;
    bool state = true;

    while (state)
    {
        getline(cin, inp);
        try
        {
            res = stoi(inp);
            if (inp.size() == to_string(res).size() && res > min)
            {
                state = false;
                return res;
            }
            else
                cout << "\nОшибка! Повторите ввод!\n";

        }
        catch (invalid_argument)
        {
            cout << "\nОшибка! Повторите ввод!\n";
        }

    }

}


void mergesortimpl(vector<int>& arr, vector<int>& buf, int left, int right) 
{
    if (left < right) 
    {
        int middle = (left + right) / 2;  

        // разделяем и сортируем
        mergesortimpl(arr, buf, left, middle);

        mergesortimpl(arr, buf, middle + 1, right);

        int k = left; 

        // слияние двух отсортированных половин
        for (int i = left, j = middle + 1; i <= middle || j <= right; )  
        {
            if (j > right || (i <= middle && arr[i] < arr[j])) 
            {
                buf[k] = arr[i];  
                ++i;  
            }
            else 
            {
                buf[k] = arr[j];  
                ++j;  
            }
            ++k;  
        }

        for (int i = left; i <= right; ++i)   
        {
            arr[i] = buf[i]; 
        }

    }
}

void mergesort(vector<int>& arr)  // сортировка слиянием
{
    if (!arr.empty()) {
        vector<int> buf(arr.size());  // создаем вектор buf, по размеру равный первоначальному вектору
        mergesortimpl(arr, buf, 0, arr.size() - 1);
    }
}


int main()
{
    srand(time(0));  // в качестве аргумента принимает зерно генератора случайных чисел;
    char ans;

    do
    {
        setlocale(LC_ALL, "Rus");
        
        cout << "\nВведите количество элементов вектора: " << endl;
        int n = check_input(0);

        vector<int> a(n);
        
        for (int i = 0; i < n; i++)
        {
            a[i] = rand();
        }

        if (n > 20)
        {
            
            cout << "\nВведено число элементов большее разумного значения!" << endl;

            cout << "\n20 элементов исходного вектора [ ";

            for (int i = 0; i < 20; i++)
            {
                cout << a[i] << " ";
            }
            cout << "]" << endl;
        }
        else
        {
            cout << "\nИсходный вектор [ ";

            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << "]" << endl;
        }

        mergesort(a);

        if (n > 20)
        {
            n = 20;

            cout << "\n20 элементов упорядоченного вектора [ ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";

            cout << "]" << endl;

            cout << "\nВведите y чтобы повторить выполнение программы! При вводе другого символа программа завершится! " << endl;
            cin >> ans;

        }
        else
        {

            cout << "\nУпорядоченный вектор [ ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";

            cout << "]" << endl;

            cout << "\nВведите y чтобы повторить выполнение программы! При вводе другого символа программа завершится! " << endl;
            cin >> ans;
        }

        cin.ignore(10000, '\n');

    } while (ans == 'y');

}