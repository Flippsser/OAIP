#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	char a;
	int n;
	cout << "Ввести количество слов: " << endl;
	cin >> n;
	cout << "Вести окончание слов: " << endl;
	cin >> a;
	for (int i = 0; i < n; i++) {
		cout << "Введите слово: ";
		cin >> str;
		if (str[str.size() - 1] == a) {
			cout << "В этом слове есть введенное окончание" << endl ;
		}
		else {
			cout << "В этом слове нет введенного окончания" << endl;
		}
	}
	return 0;
}
