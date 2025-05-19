#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    system("chcp 1251");
    // Ввод строки от пользователя
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    // Создание хеш-таблицы (unordered_map)
    unordered_map<char, int> hashTable;

    // Заполнение таблицы: подсчёт количества букв
    for (char ch : input) {
        if (isalpha(ch)) {  // Проверяем, что символ — буква
            hashTable[ch]++;
        }
    }

    // Вывод хеш-таблицы на экран
    cout << "\nХеш-таблица букв:\n";
    for (const auto& pair : hashTable) {
        cout << "Буква: " << pair.first << " | Количество: " << pair.second << endl;
    }

    // Поиск буквы в таблице
    char searchChar;
    cout << "\nВведите букву для поиска: ";
    cin >> searchChar;

    if (hashTable.find(searchChar) != hashTable.end()) {
        cout << "Буква '" << searchChar << "' встречается " << hashTable[searchChar] << " раз(а)." << endl;
    }
    else {
        cout << "Буква '" << searchChar << "' отсутствует в строке." << endl;
    }

    return 0;
}
