#include <iostream>
#include<cmath>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    double z, x, y,a,g;

    cout << "Введите число x y z: "<< endl;
    cin >> x >> y >> z;

    a = abs((x+y+z)/3);
    g= abs(sqrt(x * y * z));


    cout << "ср ар " << a << endl;
    cout << "ср геом " << g << endl;


    return 0;
}