#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double p, q;
	int d = 0;
	cout << "Ввести выручку p и выручку q: "<<endl;
	cin >> p >> q;
	if (p >= q) 
	{
		cout << "Некорректные данные" << endl;
	}
	while (p <= q)
	{
		p = p + p * 0.3;
		d = d + 1;
	}
	cout << "День: " << d << endl;
	cout << "Вывести новую выручку p: " << p << endl;
}