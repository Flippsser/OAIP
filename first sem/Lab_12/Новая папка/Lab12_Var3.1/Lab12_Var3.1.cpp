#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
    SetConsoleCP(1251);
	int i, A[15], B[15], t, countA = 0, countB = 0;
	
	cout << "Исходный массив A: " << endl;
	
	for (i = 0; i < 15; i++)
	{
		A[i] = rand() % 99;
		cout << A[i] << endl;
	}
	cout << "Исходный массив B: " << endl;
	for (i = 0; i < 15; i++)
	{
		B[i] = rand() % 99;
		cout << B[i] << endl;
	}
	
	
	cout << "Введите t: "; cin >> t;
	for (i = 0; i < 15; i++)
	{
		if (*(A + i) < t)
		{
			countA++;
		}

		if (*(B + i) < t)
		{
			countB++;
		}
	}

	int* pa, * pb;
	pa = &countA;
	pb = &countB;

	if (*pa > *pb)
	{
		cout << "Массив с наибольшим количеством элементов, меньших t: A" << endl;
	}
	else if (*pb > *pa)
	{
			cout << "Массив с наибольшим количеством элементов, меньших t: B" << endl;
	}
	else if (*pb == 0 && *pa == 0)
	{
		cout << "В массивах нет элементов, которые меньше t";
	}
	else if (*pb == *pa)
	{
		cout << "В массивах одинаковое количество элементов, которые меньше t";
	}
	

}