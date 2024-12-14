#include <iostream>
#include<cmath>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    double S,L;
    cout << "Введите длинну окружности " << endl;
    cin >> L;
    S = pow(L,2)/(4*3.14);
    cout << "Площадь круга=" << S << endl;


    return 0;
}