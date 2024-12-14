#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	const int N = 100;
	int sz, mas[N];
	int rmn = 8, rmx = 10;
	cout << "Введите размер массива ";
	cin >> sz;
	srand((unsigned)time(NULL));
	for (int i = 0; i < sz; i++)
	{
		mas[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
		cout << "Элемент" << i + 1 << " = " << mas[i] << endl;
	}
	int count = 0;
	for (int i = 0; i < sz; i++) {
		if (mas[i] == mas[i + 1]) {
			count++;
		}
	}
	cout << "Количество пар соседних элементов с одинаковым значением: " << count;
}