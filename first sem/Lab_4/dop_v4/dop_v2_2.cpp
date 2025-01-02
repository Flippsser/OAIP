#include <iostream>
using namespace std;


int main() {
    setlocale(LC_CTYPE, "Russian");
    double m, x, y;

    cout << "Введите число m: ";
    cin >> m;

    // Вычисляем первую часть
    x = (m + 5) / 2;
    // Вычисляем вторую часть
    y = x - 5;


    cout << "Первая часть: " << x << endl;
    cout << "Вторая часть: " << y << endl;


    return 0;
}