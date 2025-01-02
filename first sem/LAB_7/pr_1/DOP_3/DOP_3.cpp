#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double c1, c2;
	cout << "Введите количество воды в сосуде c1: ";
	cin >> c1;
	cout << "Введите количество воды в сосуде c2: ";
	cin >> c2;

	for (int i = 0; i <= 12; i++)
	{
		c2 = c2 + c1 / 2;
		c1 = c1 - c1 / 2;
		c1 = c1 + c2 / 2;
		c2 = c2 - c2 / 2;
	}
	cout << "Воды осталось в первом сосуде: " << c1 << ", во втором: " << c2 << endl;
	return 0;
}