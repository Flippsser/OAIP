#include <iostream>
using namespace std;

int main() {
	int a = 9;
	const int* pa = &a;
	cout << *pa << endl;
	//*pa = 12; // ошибка (нельзя менять значе-ние переменной а)
	int b = 20;
	pa = &b;
	cout << *pa;
}