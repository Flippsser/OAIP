#include <iostream>
using namespace std;
int sum(int x[])	// определение функции	
{
	int res = 0;
	for (int i = 0; i < 5; i++)
		res += x[i];
	return res;
}
int main()
{
	int mas[5], i;
	for (i = 0; i < 5; i++)
	{
		mas[i] = i * i;
		cout << mas[i] << ' ';
	}
	cout << endl << "result=" << sum(mas) << endl;
}
