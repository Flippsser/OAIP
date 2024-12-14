#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE,"Russian");
    double a, b, c,d,x1,x2;
    cout << "Введите a,b,c"<<endl;
    cin >> a >> b >> c;
    cout << a<<"x(в_квадрате)+("<<b<<")x+("<<c<<")" << endl;
    d = b * b - 4 * a * c;
    if (d < 0) {
        cout << "Корней нет";
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2*a);
        cout <<"Корни"<< x1 << " " << x2;
    }
    return 0;
}