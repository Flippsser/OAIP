#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_CTYPE, "Russian");
    float a, sum = 0,pr=1;
    int i;
    const int size = 4;
    for (i = 0; i < size; i++)
    {
        cout << "Введите а" << i << endl;
        cin >> a;
        sum = sum + a*a;
        pr = pr * a;
    }
    cout << "Ответ" << sum << endl;
    cout << "Ответ" << pr << endl;
    }
