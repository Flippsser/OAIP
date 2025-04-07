#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

// Функция для обработки строки: переносит цифры в конец строки
string processLine(const string& line) {
    queue<char> letters; 
    queue<char> digits;  

    // Проходим по строке, разделяя цифры и остальные символы
    for (char ch : line) {
        if (isdigit(ch)) {
            digits.push(ch); // Если цифра, добавляем в соответствующую очередь
        }
        else {
            letters.push(ch); // Если символ, добавляем в соответствующую очередь
        }
    }

    // Формируем итоговую строку
    string result;
    while (!letters.empty()) {
        result += letters.front();
        letters.pop();
    }
    while (!digits.empty()) {
        result += digits.front();
        digits.pop();
    }

    return result;
}

int main() {
    system("chcp 1251");
    ifstream inputFile("f.txt"); 
    ofstream outputFile("g.txt"); 

    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл f.txt для чтения!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Не удалось открыть файл g.txt для записи!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) { // Читаем файл построчно
        string processedLine = processLine(line); // Обрабатываем строку
        outputFile << processedLine << endl; // Записываем обработанную строку в файл g
    }

    inputFile.close(); 
    outputFile.close(); 

    cout << "Обработка завершена. Содержимое файла f переписано в файл g." << endl;

    return 0;
}
