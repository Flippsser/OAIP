#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    const int N = 100;
    int sz, mas[N];
    int rmn = 0, rmx = 10;
    int n=0;
    cout << "Введите размер массива ";
    cin >> sz;
    sz += 1;
    srand((unsigned)time(NULL));
    for ( int i = 0; i < sz; i++)
    {
        mas[i] = (int)(((double)rand() /
            (double)RAND_MAX) * (rmx - rmn) + rmn);
        cout << "День"<< i+1<<" = " << mas[i] << endl;
    }
    
    int week = 0;
    int sum1 = 0, k = 1;
    
    for (int i = 0; i <= sz-7; i += 7) {
        int sum = 0;
        for (int j = i; j <= i + 7; ++j) {
            sum += mas[j];
        }
        cout << "Сумма осадков " << k << " недели = " << sum << endl;
        if (sum > sum1) {
            sum1 = sum;
            week =  k;
        }
        k++;
    }
    cout << "неделя " << week << endl;
    return 0;
}