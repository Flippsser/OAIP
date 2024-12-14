#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int A[5], B[5], i, j, k, count = 0;
	for (k = 0; k < 5; k++)
	{
		*(A + k) = rand() % 9;
		*(B + k) = rand() % 9;
	}

	for (k = 0; k < 5; k++)
	{
		cout << *(A + k) << " ";
	}

	cout << endl;

	for (k = 0; k < 5; k++)
	{
		cout << *(B + k) << " ";
	}

	cout << endl;

	for (i = 0; i < 5; i++)
	{
		for (j = i; j < 5; j++)
		{
			if (*(A + i) == *(B + j))
			{
				count++;
			}
		}
	}

	cout << "Кол-во пар: " << count;

}