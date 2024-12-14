#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int x, p=0, sum = 0;
	cout << "Сколько чисел вы хотите ввести?" << endl;
	cin >> x;
	cout << "Введите чисела" << endl;
	for (int i = 1; i <= x; i++)
	{
		cin >> p;
		if (p % 2 == 0)
		{
			sum += p;
		}
	}

	cout <<"значение суммы четных элементов=" <<sum << endl;



}