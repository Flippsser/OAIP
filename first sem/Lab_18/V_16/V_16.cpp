#include <iostream>
#include <vector>
#include <string>
#include <cstdarg> 
#include <cctype>  
using namespace std;
char tolower_ru(char ch) {
    if (ch >= 'А' && ch <= 'Я') {
        return ch + ('а' - 'А');
    }
    return ch;
}
int countWordsStartingWithA(const string& sentence) {
    vector<string> words;
    size_t start = 0, end;
    while ((end = sentence.find(' ', start)) != string::npos) {
        words.push_back(sentence.substr(start, end - start));
        start = end + 1;
    }
    words.push_back(sentence.substr(start));
    int count = 0;
    for (const string& word : words) {
        if (!word.empty() && tolower_ru(word[0]) == 'а') {
            count++;
        }
    }
    return count;
}
void checkWordsWithA(int numStrings, ...) {
    va_list args;
    va_start(args, numStrings);
    for (int i = 0; i < numStrings; ++i) {
        const char* text = va_arg(args, const char*);
        string textStr(text);
        if (textStr.empty()) {
            cout << "Пустая строка!" << endl;
            continue;
        }
        int result = countWordsStartingWithA(textStr);
        cout << "В строке \"" << text << "\" количество слов на 'а': " << result << endl;
    }
    va_end(args);
}
int main() {
    setlocale(LC_ALL, "ru");
    checkWordsWithA(3,
        "Апельсин и арбуз — это фрукты.",
        "Это обычный текст без слов на 'a'(тут латинская)",
        "Академия и анализ — важные понятия.");
    cout << endl;
    checkWordsWithA(2,
        "Автомобиль и автобус — это транспорт.",
        "Тут есть слова на а автобус.");
    cout << endl;
    checkWordsWithA(1,
        "Алиса и аркадия — два разных имени.");
    return 0;
}
