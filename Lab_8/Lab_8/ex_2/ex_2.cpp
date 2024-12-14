#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double x[5] = { 9,2.7,4.1,6,12 }, p = 0, y = 0,max;
	for (int i = 1; i <= 5; i++)
	{
		y = y + pow(x[i-1], 2) + 1;
	}
	for (int i = 1; i != 5; ++i)
	{
		if (x[i] > x[i -1]) {
			max = x[i];
		}
	}
	p = y + max;
	cout << p<<endl<<max;



}