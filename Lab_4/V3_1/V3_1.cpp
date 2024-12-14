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
	cout << setw(40) << setfill(probel) << probel;
    cout << setw(1) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
    cout << setw(38) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	

	cout << setw(40) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(38) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(36) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;

	cout << setw(40) << setfill(probel) << probel;
	cout << setw(1) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(3) << setfill(c) << c << endl;
	cout << setw(38) << setfill(probel) << probel;
	cout << setw(5) << setfill(c) << c << endl;
	cout << setw(37) << setfill(probel) << probel;
	cout << setw(7) << setfill(c) << c << endl;
	cout << setw(36) << setfill(probel) << probel;
	cout << setw(9) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(11) << setfill(c) << c << endl;
	cout << setw(34) << setfill(probel) << probel;
	cout << setw(13) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(15) << setfill(c) << c << endl;


	cout << setw(39) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
	cout << setw(39) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
}
