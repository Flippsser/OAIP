#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int p_1, p_2, dp,p_11, p_22;
    printf(" введите 1ую переменную \n");
    cin >> p_1;
    p_11= p_1;
    printf(" \n введите 2ую переменную \n");
    cin >> p_2;
    p_22 = p_2;
    printf(" \n дополнительную переменную \n");
    cin >> dp;
    p_1 = p_1 * dp;
    p_2 = p_2 * dp;
    printf(" \n изменые значения с помощью доп. переменной \n");
    cout << p_1 << " " << p_2;
    printf(" \n изменые значения без использования доп. переменной \n");
    p_11 = p_11 * 3;
    p_22 = p_22 * 4;
    cout << p_11 << " " << p_22;
    return 0;

}

