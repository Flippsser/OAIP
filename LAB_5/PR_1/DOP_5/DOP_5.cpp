#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int a, b, c, r, s, t;
    cout << "Введите размеры" << endl;
    cin >> a >> b >> c >> r >> s >>t;
    if ((a < r and b < s and c < t) or
        (a < r and b < t and c < s) or
        (a < s and b < r and c < t) or
        (a < s and b < t and c < r) or
        (a < t and b < s and c < r) or
        (a < t and b < r and c < s))
    
        cout << "Да" << endl;
    else
        cout << "Нет" << endl;
    
    return 0;
}