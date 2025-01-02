#include <iostream>
#include <limits>
using namespace std;
int mn(int a, int b, int c) {
    int minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    return minValue;
}
double mn(double a, double b, double c) {
    double minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    return minValue;
}
int main() {
    setlocale(LC_ALL, "ru");
    cout << "Минимальное значение среди целых чисел: " << mn(3, 1, 5) << endl;
    cout << "Минимальное значение среди чисел с плавающей запятой: " << mn(3.5, 2.2, 5.1) << endl;

    return 0;
}