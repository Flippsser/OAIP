#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	int sz;
	const int N = 100;
	int  mas[N];
	int rmn = 8, rmx = 10;
	cout << "Введите размер массива ";
	cin >> sz;
	srand((unsigned)time(NULL));
	for (int i = 0; i < sz; i++)
	{
		mas[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << "День" << i + 1 << " = " << mas[i] << endl;
	}
	
	int count = 0;
	for (int i = 0; i < sz-1; i++) {
		if (mas[i] == mas[i + 1]) {
			count++;
		}
		else
		{
			if(mas[i] = mas[i + 1])
			count = 0;
		}
	}
	cout << "наибольшее число подряд идущих одинаковых элементов = " << count;
}