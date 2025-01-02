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
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(41) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(13) << setfill(c) << c << endl;

	cout << setw(37) << setfill(probel) << probel;
	cout << setw(17) << setfill(c) << c << endl;
	cout << setw(36) << setfill(probel) << probel;
	cout << setw(19) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(17) << setfill(c) << c << endl;
	


	cout << setw(39) << setfill(probel) << probel;
	cout << setw(13) << setfill(c) << c << endl;
	cout << setw(41) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;
	cout << setw(43) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
}
