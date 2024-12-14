#include <iostream>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	const int N = 1000;
	int i, sz, A[N], dob=0,memory=0;
	int rmn = -99, rmx = 99;
	int k,j;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Массив А:" << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand() /
			(double)RAND_MAX) * (rmx - rmn) + rmn);
	}
	for (int i = 0; i < sz; i++)
	{
		cout << "A[" << i << "]" << "\t" << A[i] << endl;
	}
	cout << endl;
	cout << "Массив значений без элементов кратных 7:" << endl;
	for (i = 0; i < sz; i++)
	{
		if (i % 7 == 0)
		{
			k = 0;
			for (i = 1; i < sz; i++)
			{
				if ((i + k) % 7 == 0)
				{
					k++;
					sz--;
				}
				A[i] = A[i + k];
			}
		}
	}
	for (int i = 0; i < sz; i++)
	{
		cout << "A[" << i << "]" << "\t" << A[i] << endl;
	}
	cout << endl;
	
	cout << "Добавить после  каждого нечетного элемента массива элемент со значением 4:" << endl;
	for (int i = 0; i < sz; ++i)
	{
		if (A[i] % 2 != 0) {
			for ( j = (sz-1); j > i; j--)
				A[j + 1] = A[j];
			sz++;
			A[i + 1] = 4;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		cout << "A[" << i << "]" << "\t" << A[i] << endl;
	}
	cout << endl;
}