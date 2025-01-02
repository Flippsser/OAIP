#include <iostream>
#include <iomanip> 
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	char c, probel; probel = ' ';
	char z;
	cout << "Введите символ "; cin >> c;
	cout << "Введите переменную "; cin >> z;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;

	cout << setw(33) << setfill(probel) << probel;
	cout << setw(14) << setfill(z) << z << endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(12) << setfill(z) << z << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(10) << setfill(z) << z << endl;

	cout << setw(35) << setfill(probel) << probel;

}
