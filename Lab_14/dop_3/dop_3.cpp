#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int n = 5;
	int A[n][n], B[n], column = 0, row = 0, i, j, max = 0, k;
	cout << "Исходная матрица: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand() % 50 + 10;
			cout << setw(2) << A[i][j] << " ";
		}
		cout << endl;
	}

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (A[i][j] > max && A[i][j] != B[0] && A[i][j] != B[1] && A[i][j] != B[2] && A[i][j] != B[3] && A[i][j] != B[4])
				{
					max = A[i][j];
					B[k] = A[i][j];
				}
			}
		}
		max = 0;
	}

	k = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				A[i][j] = B[k];
				k++;
			}
		}
	}

	cout << endl << "Полученная матрица: " << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(2) << A[i][j] << " ";
		}
		cout << endl;
	}
}