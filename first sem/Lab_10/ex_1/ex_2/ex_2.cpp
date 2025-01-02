#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, k, size = 4;
	float massivA[] = { 5, -4, 17.1, 9, 1 },sr=0;
	cout << "Введите номер элемента (от 0 до 4)";
	cin >> k;
	for (i = 0; i <= size; i++) {
		sr += massivA[i];
	}
	sr = sr / (size + 1);
	for (i = k; i <= size; i++)
		massivA[i] = massivA[i + 1];
	size--;
	for (i = 0; i <= size; i++)
		cout << massivA[i] << endl ;
	cout << endl << sr << endl;
}

