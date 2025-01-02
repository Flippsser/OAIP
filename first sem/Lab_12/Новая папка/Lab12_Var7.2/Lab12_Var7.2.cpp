#include <iostream>
using namespace std;
int main()
{
    
    int N, k;
    cout << "Введите число N: ";
    cin >> N;
    cout << "Введите число k: ";
    cin >> k;
    int mas[10] = { 0 };
    int count = 0;
    
    while (N > 0) {
        int digit = N % 10;
        if (digit % k == 0) 
        {
            mas[count] = digit;
            count++;
        }
        N /= 10;
    }
    
    for (int i = 0; i < count / 2; i++) 
    {
        int a = mas[i];
        mas[i] = mas[count - i - 1];
        mas[count - i - 1] = a;
    }
    
    cout << "Цифры, кратные " << k << ": ";
    for (int i = 0; i < count; i++) 
    {
        cout << mas[i] << ' ';
    }
    return 0;
}