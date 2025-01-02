#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	float a, sum = 1;
	int i;
	cout << "Введите а" << endl;
	cin >> a;
	for (i = 1; i != a + 1; ++i) {
		sum *= i;
	}
	cout << "Ответ " << sum << endl;
}
