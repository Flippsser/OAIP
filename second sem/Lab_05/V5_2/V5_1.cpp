#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Объединение для хранения информации о происхождении книги
union Origin {
    char purchase[50]; // Покупка
    char theft[50];    // Кража
    char gift[50];     // Подарок
};

// Структура для представления книги
struct Book {
    string author;        // Автор книги
    string title;         // Название книги
    string publisher;     // Издательство
    string section;       // Раздел библиотеки
    Origin origin;        // Происхождение
    bool isAvailable;     // Наличие книги
};

// Функция для ввода данных книги с клавиатуры
Book inputBook() {
    Book book;
    cout << "Введите автора книги: ";
    getline(cin >> ws, book.author);
    cout << "Введите название книги: ";
    getline(cin, book.title);
    cout << "Введите издательство: ";
    getline(cin, book.publisher);
    cout << "Введите раздел библиотеки (специальная литература, хобби и т.д.): ";
    getline(cin, book.section);

    int originChoice;
    cout << "Выберите происхождение книги (1 - покупка, 2 - кража, 3 - подарок): ";
    cin >> originChoice;
    cin.ignore();
    switch (originChoice) {
    case 1:
        cout << "Введите детали покупки: ";
        cin.getline(book.origin.purchase, 50);
        break;
    case 2:
        cout << "Введите детали кражи: ";
        cin.getline(book.origin.theft, 50);
        break;
    case 3:
        cout << "Введите детали подарка: ";
        cin.getline(book.origin.gift, 50);
        break;
    default:
        cout << "Некорректный выбор происхождения!" << endl;
    }

    cout << "Книга в наличии? (1 - да, 0 - нет): ";
    cin >> book.isAvailable;

    return book;
}

// Функция для записи всех данных в файл
void writeToFile(const vector<Book>& library, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    for (const auto& book : library) {
        file.write((char*)&book, sizeof(Book));
    }
    file.close();
    cout << "Данные успешно записаны в файл." << endl;
}

// Функция для чтения данных из файла
vector<Book> readFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return {};
    }
    vector<Book> library;
    Book book;
    while (file.read((char*)&book, sizeof(Book))) {
        library.push_back(book);
    }
    file.close();
    return library;
}

// Функция для вывода всех книг на экран
void printBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "Библиотека пуста." << endl;
        return;
    }
    for (const auto& book : library) {
        cout << "Автор: " << book.author << endl;
        cout << "Название: " << book.title << endl;
        cout << "Издательство: " << book.publisher << endl;
        cout << "Раздел: " << book.section << endl;
        cout << "Доступность: " << (book.isAvailable ? "В наличии" : "Нет в наличии") << endl;
        cout << endl;
    }
}

// Функция для поиска книг по автору
void searchByAuthor(const vector<Book>& library, const string& author) {
    bool found = false;
    for (const auto& book : library) {
        if (book.author == author) {
            cout << "Название: " << book.title << endl;
            cout << "Издательство: " << book.publisher << endl;
            cout << "Раздел: " << book.section << endl;
            cout << "Доступность: " << (book.isAvailable ? "В наличии" : "Нет в наличии") << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Книги данного автора не найдены." << endl;
    }
}

// Главное меню программы
int main() {
    system("chcp 1251");
    vector<Book> library;
    string filename = "library.dat";

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Сохранить в файл\n";
        cout << "3. Загрузить из файла\n";
        cout << "4. Показать все книги\n";
        cout << "5. Найти книгу по автору\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.push_back(inputBook());
            break;
        case 2:
            writeToFile(library, filename);
            break;
        case 3:
            library = readFromFile(filename);
            break;
        case 4:
            printBooks(library);
            break;
        case 5: {
            string author;
            cout << "Введите автора для поиска: ";
            getline(cin >> ws, author);
            searchByAuthor(library, author);
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
