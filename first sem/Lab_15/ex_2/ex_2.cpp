#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	char* pStr;
	char c, * pc;
	int j, length, count = 0;
	cout << "Введите размер строки: ";
	cin >> length;
	pStr = new char[length + 1];
	cout << "Введите строку: ";
	cin >> pStr;
	cout << "Введите символ: ";
	cin >> c;
	pc = &c;
	for (j = 0; j < length; j++) {
		if (pStr[j] == *pc) {
			count++;
		}
	}
	cout << count << " Повторений символа " << c << endl;
	delete[] pStr;
}
