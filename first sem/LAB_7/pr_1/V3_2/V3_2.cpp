#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, count = 0;
    cout << "Введите сумму (n): ";
    cin >> n;
    for (int i = 100; i <= 999; ++i)
    {
        int sum = (i / 100) + ((i / 10) % 10) + (i % 10); 
        if (sum == n)
        {
            ++count;
        }
    }
    cout << "Количество трёхзначных чисел, сумма цифр которых равна " << n << ": " << count << endl;
    return 0;
}


