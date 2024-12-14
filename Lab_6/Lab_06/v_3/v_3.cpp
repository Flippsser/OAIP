#include <iostream>
#include<cmath>
void main()
{
	setlocale(LC_ALL, "RUS");
	using namespace std;
	float z, q, y = -1.55, j;
	int a = 6;
	for (int i = 1; i < 5; i++)
	{
		cout << "Введите j" << endl;
		cin >> j;
		z = sqrt(a + 1) - tan(j + y) ;
		q = exp(-j*0.1*y) + pow(3 * z, 2);
		cout << "z = " << z << endl;
		cout << "q = " << q << endl;
		cout << endl;
	}

} 