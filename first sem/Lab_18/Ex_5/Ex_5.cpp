#include <iostream>
#include <cstdarg>
#include <limits.h>
using namespace std;
int fmax(int n, ...) {
    va_list args;
    va_start(args, n);
    int min = va_arg(args, int);
    for (int i = 1; i < n; i++) {
        int val = va_arg(args, int);
        if (val < min) {
            min = val;
        }
    }
    va_end(args);
    return min;
}
double fmax(double n, ...)
{
    double* p = &n;
    double min = *p;
    int k = *p;
    for (int i = 0; i < k; i++)
    {
        if (min > *(p + i))
        {
            min = *(p + i);
        }
    }
    return min;
}
int main()
{
    setlocale(LC_CTYPE, "Russian");
    cout << fmax(5, 2, 3, 4, 5, 1) << endl;
    cout << fmax(6, 3, 21, 56, 22, 7, 4) << endl;
    cout << fmax(3.0, 1.7, -5.5, 0.0) << endl;
    cout << fmax(4.0, 3.33, -1.44, -7.99, 2.22) << endl;
    return 0;
}
