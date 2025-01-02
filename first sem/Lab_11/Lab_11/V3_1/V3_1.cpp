#include <iostream>
#include <bitset>
#include <Windows.h>
using namespace std;

void main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    unsigned int A;
    char tmp[33];
    cout << "Введите целое число: ";
    cin >> A;


    unsigned int maskA = 0;
    for (int i = 2; i <= 13; i++)
    {
        maskA |= (1 << i);
    }
    A ^= maskA;
    _itoa_s(A, tmp, 2);
    cout << "Результат после инвертирования битов со 2 по 14: " << tmp << endl;

}