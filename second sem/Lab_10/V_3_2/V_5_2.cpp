#include <iostream>
using namespace std;

//вычисление биномиального коэффициента C(m, n)
int binomialCoefficient(int m, int n) {
    // Базовые случаи: C(n, 0) = 1 и C(n, n) = 1
    if (m == 0 || m == n) {
        return 1;
    }
    // Рекурсивный случай: C(m, n) = C(m, n-1) + C(m-1, n-1)
    return binomialCoefficient(m - 1, n - 1) + binomialCoefficient(m, n - 1);
}

int main() {
    system("chcp 1251");
    int n, m;
    cout << "Введите значение n (0 <= m <= n): ";
    cin >> n;
    cout << "Введите значение m (0 <= m <= n): ";
    cin >> m;
    if (m < 0 || m > n) {
        cout << "Ошибка: m должно быть в диапазоне [0, n]!" << endl;
        return 1;
    }

    cout << "Биномиальный коэффициент C(" << m << ", " << n << ") = "
        << binomialCoefficient(m, n) << endl;

    return 0;
}
