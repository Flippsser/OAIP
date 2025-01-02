#include <iostream>
int* pfmin(int* p, int n);
void main()
{
	int masB[5] = { 4, 8, 2, 6, 4 };
	(*pfmin(masB, 5))++;
	for (int i = 0; i < 5; i++)
		std::cout << masB[i] << ' ';
}
int* pfmin(int* p, int n)
{
	int* pmin;
	for (pmin = p; n > 0; p++, n--)
		if (*p < *pmin)
			pmin = p;
	return pmin;
}
