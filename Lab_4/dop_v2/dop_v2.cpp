#include <iostream>
#include <iomanip> 
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	char c, probel;
	probel = ' ';
	printf(" Введите символ \n");
	cin >> c;
	cout << setw(43) << setfill(probel) << probel;
	cout << setw(2) << setfill(c) << c << endl;
	cout << setw(41) << setfill(probel) << probel;
	cout << setw(6) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;

	cout << setw(37) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(14) << setfill(c) << c << endl;


	cout << setw(39) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(41) << setfill(probel) << probel;
	cout << setw(6) << setfill(c) << c << endl;
	cout << setw(43) << setfill(probel) << probel;
	cout << setw(2) << setfill(c) << c << endl;
}
