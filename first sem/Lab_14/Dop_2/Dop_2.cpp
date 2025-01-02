#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int A[200][200];
	int n, t;
	cout << "Введите n: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		t = i + 1;
		for (int j = 0; j < n; j++) {
			A[i][j] = t;
			t++;
			if (t > n) t = 1;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
