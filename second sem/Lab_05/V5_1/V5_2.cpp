#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

enum Origin {
    PURCHASE,
    THEFT,
    GIFT
};

struct LibrarySection {
    unsigned int isAvailable : 1;
    unsigned int section : 3;
};

struct Book {
    string author;
    string title;
    string publisher;
    int year;
    LibrarySection sectionInfo;
    Origin origin;
};

string originToString(Origin origin) {
    switch (origin) {
    case PURCHASE: return "Покупка";
    case THEFT: return "Кража";
    case GIFT: return "Подарок";
    default: return "Неизвестно";
    }
}

string sectionToString(unsigned int section) {
    switch (section) {
    case 0: return "Специальная литература";
    case 1: return "Хобби";
    case 2: return "Домашнее хозяйство";
    case 3: return "Беллетристика";
    default: return "Другой раздел";
    }
}

Book inputBook() {
    Book book = {};
    cout << "Введите автора книги: ";
    getline(cin >> ws, book.author);
    cout << "Введите название книги: ";
    getline(cin, book.title);
    cout << "Введите издательство: ";
    getline(cin, book.publisher);
    cout << "Введите год публикации книги: ";
    cin >> book.year;

    int isAvailable, section, originInput;
    cout << "Книга доступна? (1 - Да, 0 - Нет): ";
    cin >> isAvailable;
    book.sectionInfo.isAvailable = isAvailable;

    cout << "Введите раздел библиотеки (0 - Специальная литература, 1 - Хобби, 2 - Домашнее хозяйство, 3 - Беллетристика): ";
    cin >> section;
    book.sectionInfo.section = section;

    cout << "Введите происхождение книги (0 - Покупка, 1 - Кража, 2 - Подарок): ";
    cin >> originInput;
    book.origin = static_cast<Origin>(originInput);

    return book;
}

void printBook(const Book& book) {
    cout << "Автор: " << book.author << endl;
    cout << "Название: " << book.title << endl;
    cout << "Издательство: " << book.publisher << endl;
    cout << "Год публикации: " << book.year << endl;
    cout << "Раздел библиотеки: " << sectionToString(book.sectionInfo.section) << endl;
    cout << "Наличие: " << (book.sectionInfo.isAvailable ? "В наличии" : "Отсутствует") << endl;
    cout << "Происхождение: " << originToString(book.origin) << endl;
}

void searchByYear(const vector<Book>& library, int year) {
    bool found = false;
    for (const auto& book : library) {
        if (book.year == year) {
            printBook(book);
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Книги, опубликованные в указанном году, не найдены." << endl;
    }
}

void deleteBook(vector<Book>& library, const string& title) {
    auto it = remove_if(library.begin(), library.end(), [&title](const Book& book) {
        return book.title == title;
        });
    if (it != library.end()) {
        library.erase(it, library.end());
        cout << "Книга удалена." << endl;
    }
    else {
        cout << "Книга с указанным названием не найдена." << endl;
    }
}

void printLibrary(const vector<Book>& library) {
    for (const auto& book : library) {
        printBook(book);
        cout << endl;
    }
}

int main() {
    system("chcp 1251");
    vector<Book> library;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Показать все книги\n";
        cout << "3. Найти книги по году публикации\n";
        cout << "4. Удалить книгу\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.push_back(inputBook());
            break;
        case 2:
            printLibrary(library);
            break;
        case 3: {
            int year;
            cout << "Введите год публикации: ";
            cin >> year;
            searchByYear(library, year);
            break;
        }
        case 4: {
            string title;
            cout << "Введите название книги для удаления: ";
            getline(cin >> ws, title);
            deleteBook(library, title);
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
