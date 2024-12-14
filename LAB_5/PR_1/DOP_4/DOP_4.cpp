#include <iostream>/
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double r, p, q;
	cout << "Введите радиус шара и значение двух диагоналей через пробел: ";
	cin >> r >> p >> q;
	if ((p * q) / (sqrt(p*p + q*q)) >= r)
	{
		cout << "Да, пройдёт";
	}
	else
		cout << "Нет, не пройдет";
	return 0;
}