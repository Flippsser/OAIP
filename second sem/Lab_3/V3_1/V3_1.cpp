#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream FILE1("file1.txt");
	ofstream FILE2("file2.txt");
	string words[12]{ "a","o","u","i","e","y","A","O","U","I","E","Y" };
	cout << "enter k:";
	int k, iter = 1, count = 0;
	cin >> k;
	cout << endl;
	string temp;
	while (!FILE1.eof()) {
		iter++;
		getline(FILE1, temp);
		if (iter > k && iter <= k + 3) {
			FILE2 << temp << endl;
			cout  << temp << endl;
			for (int i = 0; i != 11; i++) {
				if (temp == words[i])
					count++;
			}
		}
	}
	cout << "Кол-во гласных: " << count; 
	return 0;
}