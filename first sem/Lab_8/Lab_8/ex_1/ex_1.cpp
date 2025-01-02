#include <iostream>
#include<cmath>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double x[5] = {-2,6,1.1,2.7,4},sum=0;
	for (int i = 1; i <=5; i++)
	{
		sum = sum+pow(x[i-1] - 2, 2);
	}
	sum = sum +8*x[3];
	cout << sum;
}



