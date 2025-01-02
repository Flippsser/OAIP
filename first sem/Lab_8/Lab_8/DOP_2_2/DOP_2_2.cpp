#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int x, p = 0, otr=0,l=0;
	cout << "Сколько чисел вы хотите ввести?" << endl;
	cin >> x;
	cout << "Введите чисела" << endl;
	for ( int i = 1; i <= x; i++)
	{
		cin >> p;
		if (p < 0)
		{
			otr = p;
			l = i;
		}
	}

	cout << "последний отрицательный=" << otr << endl;
	cout << "порядковый номер последнего отрицательного элемента=" << l << endl;


}