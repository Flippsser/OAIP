#include <iostream>
using namespace std;
void main()
{
	char t[3][20];
	int i, n;
	cout << "Input size (<=3): ";
	cin >> n;
	cin.ignore(cin.rdbuf()->in_avail());
	for (i = 0; i < n; i++)
	{
		cout << "Input string: ";
		gets_s(t[i]);
	}
	for (i = 0; i < n; i++)
		puts(t[i]);
}
