#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b, p, q, r, s;
	cout << "Введите сторону a: "; cin >> a;
	cout << "Введите сторону b: "; cin >> b;
	cout << "Введите сторону p: "; cin >> p;
	cout << "Введите сторону q: "; cin >> q;
	cout << "Введите сторону r: "; cin >> r;
	cout << "Введите сторону s: "; cin >> s;
	if ((a >= (p + r)) and (b >= q and b >= s))
	{
		cout << "Можно построить 2 дома";
	}
	else if ((a >= (p + s)) and (b >= q and b >= r))
	{
		cout << "Можно построить 2 дома";
	}
	else if ((a >= (q + r)) and (b >= p and b >= s))
	{
		cout << "Можно построить 2 дома";
	}
	else if ((a >= (q + s)) and (b >= p and b >= r))
	{
		cout << "Можно построить 2 дома";
	}
	else
		cout << "Нельзя построить 2 дома";
	return 0;
}