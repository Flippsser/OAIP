#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	int a[100], n, mini=0, maxi=0, count;
	cout << "Введите размер масcива" << endl;
	cin >> n;
	cout << "Введите значения" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i-1]) {
			mini = i;
		}
		if (a[i] > a[i-1]) {
			maxi = i;
		}
	}
	count = abs(maxi - mini)-1 ;
	cout << count << endl;

}