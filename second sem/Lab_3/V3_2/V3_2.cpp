#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	system("chcp 1251");
	system("pause");
	setlocale(LC_ALL, "Russian");
	char symbol[] = {'1','2','3','4','5','6','7','8','9','0'};
	fstream FILE1("file1.txt");
	string words;
	getline(cin,words);
	FILE1 << words << endl;
	FILE1.close();
	string OUTPUT;
	fstream FILE("file1.txt");
	getline(FILE, OUTPUT);
	for (int i = 0; i < OUTPUT.length(); i++) {
		for (int j = 0; j < 10; j++) {
			if (OUTPUT[i] == symbol[j]) {
				OUTPUT.erase(i, 1);
				i--; 
				break;
			}
		}
	}
	cout << OUTPUT;
	FILE.close();
	fstream FILE2("file2.txt");
	FILE2 << OUTPUT;
	FILE2.close();
	return 0;
}