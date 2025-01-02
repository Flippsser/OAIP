#include <iostream>
#include <cstdlib> 
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    char s[33];
    unsigned int A, B;
    int n, p, m, q;

    cout << "Введите первое число A=";
    cin >> A;
    cout << "Введите второе число B=";
    cin >> B;
    cout << "Введите количество бит для инвертирования(n): ";
    cin >> n;
    cout << "Введите позицию (p), с которой инвертировать биты в числе A: ";
    cin >> p;
    cout << "Введите количество битов m, которые необходимо заменить: ";
    cin >> m;
    cout << "Введите позицию (q), на место которой нужно провести замену в числе B: ";
    cin >> q;

    _itoa_s(A, s, 33, 2);
    cout << "A=" << s << endl;
    _itoa_s(B, s, 33, 2);
    cout << "B=" << s << endl;


    int maskA = ((1 << n) - 1) << (p - n + 1);
    _itoa_s(maskA, s, 33, 2);
    cout << "Маска для инвертирования A: " << s << endl;

    A ^= maskA;
    _itoa_s(A, s, 33, 2);
    cout << "Инвертированные биты в A: " << s << endl;


    int ex = (A & maskA) >> (p - n + 1);


    int maskB = ((1 << m) - 1) << q;
    B &= ~maskB;


    B |= (ex << q);
    _itoa_s(B, s, 33, 2);
    cout << "Результат B=" << s << endl;

    _itoa_s(A, s, 33, 2);
    cout << "A=" << s << endl;

    _itoa_s(B, s, 33, 2);
    cout << "B=" << s << endl;

    return 0;
}
