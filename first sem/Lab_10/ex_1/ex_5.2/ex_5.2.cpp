#include <iostream>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	const int N = 100;
	int i, sz, A[N], dob = 0, memory = 0;
	int rmn = -99, rmx = 99;
	int k, j;
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
	cout << "все отрицательные элементы массива перенести в начало, а все остальные – в конец.:" << endl;
	for (i = 0; i < sz; i++)
	{
		if (A[i] < 0)
		{
			memory = A[i];
			for (j = i; j > 0; j--)
			{
				A[j] = A[j - 1];
			}
			
				A[0] = memory;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		cout << "A[" << i << "]" << "\t" << A[i] << endl;
	}
	
}