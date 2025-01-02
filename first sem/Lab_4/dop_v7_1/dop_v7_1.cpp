#include <iostream>
#include <iomanip> 
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	char c, probel;
	int p, s;
	p = 43;
	s = 43;
	probel = ' ';
	printf(" Введите символ \n");
	cin >> c;
	for (int i = 1; i < 43; i++) {
		cout << setw(p) << setfill(probel) << probel;
		cout << setw(s) << setfill(c) << c << endl;
		p = p - 1;
		s = s + 2;
	}
}
