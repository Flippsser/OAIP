﻿#include <iostream>
using namespace std;

double& dmin(double A[], int size);

void main()
{
	double s;
	const int size = 5;
	double A[] = { 6, 4.2, 2, 1.2, 111 };
	s = dmin(A, size);
	cout << s << endl;
	for (int i = 0; i < size; i++)
		cout << " " << A[i];
	cout << endl;
	dmin(A, size) = 1.0;       // изменение минимума на значение 1.0 
	for (int i = 0; i < size; i++)
		cout << " " << A[i];
}

double& dmin(double A[], int size)
{
	int i, j = 0;
	for (i = 1; i < size; i++)
		if (A[j] > A[i])
			j = i;
	return A[j];
}
