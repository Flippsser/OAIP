#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    double a, b, c, sa,sg;
    cout << "Введите a,b,c" << endl;
    cin >> a >> b >> c;
    if (a!=0 and b!=0 and c!=0) {
        sg = sqrt(a * b * c);
        cout << "Среднее геометрическое=" << sg; 
    }
    else
    {
        sa = (a + b + c)/3;
        cout << "Среднее арифметическое=" << sa;
    }
    return 0;
}