#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int a, b, k = 0;
	cout << "Введите последовательность чисел(0 для окончания): ";
	cin >> a;
	while (a != 0)
	{
		b = a;
		cin >> a;
		if ((a > 0 && b < 0) || (a < 0 && b>0))
			k = k + 1;
	}
	cout << "Количество смен знаков: " << k << endl;
}