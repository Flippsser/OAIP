#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float z, q, y = -1.55, j,a;
	int i = 0;
	while (i < 3)
	{
		cout << "Введите j: ";
		cin >> j;
		for (a=1; a < 2; a=a + 0.2)
		{
			z = sqrt(a + 1) - tan(j + y);
			q = exp(-j * 0.1 * y) + pow(3 * z, 2);
			cout << "z=: " << z << endl;
			cout << "q=: " << q << endl<< endl;
			
		}
		cout << endl;
		i = i + 1;
	}
	return 0;
}
