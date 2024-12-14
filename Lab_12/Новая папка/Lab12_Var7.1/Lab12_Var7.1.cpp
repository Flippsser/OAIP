#include <iostream>
using namespace std;
int main()
{
	int k, n;
	cout << "Введите число k: ";
	cin >> k;
	cout << "Введите размер массива: ";
	cin >> n;

	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 99;
		cout << A[i] << endl;
	}
	
	cout << endl;
	
	cout << "Номер чисел, которые равны k: ";
	for (int i = 0; i < n; i++) {
		if (*(A + i) == k)
			cout << i + 1 << ' ';
	}
	cout << endl;
	
	cout << "Номера чисел, которые больше k: ";
	for (int i = 0; i < n; i++) {
		if (*(A + i) > k)
			cout << i + 1 << ' ';
	}
	cout << endl;
	
	cout << "Номера чисел, которые меньше k: ";
	for (int i = 0; i < n; i++) {
		if (*(A + i) < k)
			cout << i + 1 << ' ';
	}
	cout << endl;
	delete[] A;
	return 0;
}