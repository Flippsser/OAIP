#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int a, b, c, sum;
    cout << "Введите a,b,c" << endl;
    cin >> a >> b >> c;
    if ((a % 5) == 0 and (b % 5) == 0 and (c % 5) == 0) {
        cout << "\nError";
        return 0;
    }

    if ((a % 5)==0) {                    
        a = a;
    }
    else {                       
        a = 0;
    }

    if ((b % 5) == 0) {
        b = b;
    }
    else {
        b= 0;
    }

    if ((c % 5) == 0) {
        c = c;
    }
    else {
        c = 0;
    }
    sum = a + b + c;
    cout << endl<<sum;
    return 0;
}