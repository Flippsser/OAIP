#include <iostream>
#include <cmath> 
using namespace std;

double calculate_recurs(int k, int n) {
    if (k == n) {
        return sqrt(1.0 + (n + n));
    }
    else if (k < n) {
        // Вычисляем sqrt(1 + (n + k) * результат_для(k+1, n))
        return sqrt(1.0 + (n + k) * calculate_recurs(k + 1, n));
    }
}

int main() {
    int n;
    system("chcp 1251");

    cout << "Введите натуральное число n (n >= 1): ";
    cin >> n;

    if (n < 1) {
        cout << "Ошибка: n должно быть натуральным числом (больше или равно 1)." << endl;
        return 0;
    }

    double result = calculate_recurs(1, n);
    cout << "Результат вычисления выражения для n = " << n << " равен:" << endl << result;

    return 0;
}