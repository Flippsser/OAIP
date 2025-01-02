#include <iostream>
int main()
{
	using namespace std;
	
	srand((unsigned)time(NULL));
	const int N = 100;
	int C[N], D[N], m, * pC, * pD, n = 0, l = 0, p = 0;
	cout << "Введите размер массивов : ";
	cin >> m;
	
	for (pC = C; pC < C + m; pC++)
	{
		*pC = rand() % 99;
	}
	cout << "C = { ";
	
	for (pC = C; pC < C + m; pC++)
	{
		cout << *pC << " ";
	}
		cout << "}" << endl;
	
	for (pD = D; pD < D + m; pD++)
	{
		*pD = rand() % 99;
	}
	cout << "B = { ";
	
	for (pD = D; pD < D + m; pD++) 
	{
		cout << *pD << " ";
	}
		
	cout << "}" << endl;
	
	
	for (int k = 0; k < m; k++)
	{
		if (C[k] > D[k]) 
		{
			l++;
		}
		else if(C[k]<D[k])
		{
			p++;
		}
		else
		{
			n++;
		}
	}
	
	cout << "Количество элементов, для которых C[k] > D[k]: " << l << endl;
	cout << "Количество элементов, для которых C[k] < D[k]: " << p << endl;
	cout << "Количество элементов, для которых C[k] = D[k]: " << n << endl;

	return 0;
}