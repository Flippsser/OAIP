#include <iostream>
#include <Windows.h>
using namespace std;

void task1(int A[], int size) {
	int maxNum = A[0];
	for (int i = 1; i != size; ++i) {
		if (A[i] > maxNum) {
			maxNum = A[i];
		}
	}

	int counter = 0;
	for (int i = 0; i != size; ++i) {
		if (A[i] == maxNum) {
			++counter;
		}
	}

	cout << counter << endl;
}

void task2(char arr[], int len) {
	int letCounter = 0;
	int maxLet = 0, minLet = 100;
	int maxLetPos = 0, minLetPos = 0;
	for (int i = 0; i != len; ++i) {

		if (arr[i] == ' ' || arr[i] == '\0') {
			if (letCounter != 0) {

				if (letCounter > maxLet) {
					maxLet = letCounter;
					maxLetPos = i;
				}
				if (letCounter < minLet) {
					minLet = letCounter;
					minLetPos = i;
				}

			}

			letCounter = 0;
		}
		else {
			++letCounter;
		}
	}

	cout << "Max lenght word: ";
	for (int i = maxLetPos - maxLet; i != maxLetPos; ++i) {
		cout << arr[i];
	}
	cout << endl << "Min lenght word: ";
	for (int i = minLetPos - minLet; i != minLetPos; ++i) {
		cout << arr[i];
	}
	cout << endl;

}

int main() {
	setlocale(LC_ALL, "RU");
	

	int choice;
	int size;
	do
	{
		cout << "Выберите Задание:" << endl;
		cout << "1 - Задание 1" << endl;
		cout << "2 - Задание 2" << endl;
		cout << "3 - выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			int* A;
			cout << "Введите размерность: ";
			cin >> size;
			A = new int[size];

			for (int i = 0; i != size; ++i) {
				cout << "A[" << i << "]: ";
				cin >> A[i];
			}

			task1(A, size);

			delete[] A;
			break;
		case 2:
			char* str;
			int size;
			cout << "Введите размер строки: ";
			cin >> size;
			cin.ignore();
			str = new char[size + 1];

			cin.getline(str, size + 1);

			str[size] = '\0';

			task2(str, size + 1);

			delete[] str;
			break;
		case 3:  break;
		}
	} while (choice != 3);

}