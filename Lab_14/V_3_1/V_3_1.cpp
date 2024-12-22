#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n, m;
	cout << "Введите количество строк (n): ";
	cin >> n;
	cout << "Введите количество столбцов (m): ";
	cin >> m;
	srand(time(0));
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[m];
	}
	cout << "Элементы матрицы:\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			A[i][j] = rand() % 100;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			sum += A[i][j];
		}
	}
	if (sum % 2 == 0)
	{
		cout << "Сумма элементов матрицы является четным числом." << endl;
	}
	else
	{
		cout << "Сумма элементов матрицы является нечетным числом." << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		delete[] A[i];
	}
	delete[] A;
	return 0;
}