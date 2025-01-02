#include <iostream>
using namespace std;
double e = 0.001;

void dihotomiya(extern double a, extern double b, double(*f)(double))
{
	double x;
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if ((*f)(a) * (*f)(x) <= 0)
			b = x;
		else a = x;
	}
	cout << "x = " << x << endl;
}
double f1(double x)
{
	return cos(x) + x - 7;
}
double f2(double x)
{
	return  exp(x) - 1 / x;
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b;
	cout << "Введите границы отрезков" << endl;
	cin >> a;
	cin >> b;
	dihotomiya(a, b, f1);
	dihotomiya(a, b, f2);

	return 0;
}