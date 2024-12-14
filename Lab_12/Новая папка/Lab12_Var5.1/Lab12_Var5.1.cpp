#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	int A[100], fst[100], snd[100], n, k = 0, p = 0, i;
	double average, sum = 0;
	cout << "Введите кол-во элементов в массиве: "; 
	cin >> n;
	cout << "Исходный массив " << endl;
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % 99;
		cout << A[i] << endl;
	}

	for (i = 0; i < n; i++)
	{
		sum = sum + *(A + i);
	}

	average = sum / n;

	cout << "Среднее: " << average << endl;

	for (i = 0; i < n; i++)
	{
		if (*(A + i) > average)
		{
			fst[k] = *(A + i);
			k++;
		}

		if (*(A + i) < average)
		{
			snd[p] = *(A + i);
			p++;
		}
	}

	cout << "Первая часть: ";

	for (i = 0; i < k; i++)
	{
		cout << *(fst + i) << " ";
	}

	cout << endl;

	cout << "Вторая часть: ";

	for (i = 0; i < p; i++)
	{
		cout << *(snd + i) << " ";
	}
}