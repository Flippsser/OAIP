#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Объединение для хранения данных о клиенте и заложенном товаре
union PawnData {
    struct {
        char clientName[50];       // Анкетные данные клиента
        char itemName[50];         // Наименование товара
        double estimatedValue;     // Оценочная стоимость
        double pledgedAmount;      // Сумма, выданная под залог
        char pawnDate[15];         // Дата сдачи
        int storageDuration;       // Срок хранения (в днях)
    };
};

// Структура для хранения данных
struct Pawn {
    PawnData data;
};

// Функция для ввода данных о залоге
void inputPawn(vector<Pawn>& pawns) {
    Pawn pawn;

    cout << "Введите анкетные данные клиента: ";
    cin.ignore();
    cin.getline(pawn.data.clientName, 50);

    cout << "Введите наименование товара: ";
    cin.getline(pawn.data.itemName, 50);

    cout << "Введите оценочную стоимость товара: ";
    cin >> pawn.data.estimatedValue;

    cout << "Введите сумму, выданную под залог: ";
    cin >> pawn.data.pledgedAmount;

    cout << "Введите дату сдачи (формат DD.MM.YYYY): ";
    cin >> pawn.data.pawnDate;

    cout << "Введите срок хранения (в днях): ";
    cin >> pawn.data.storageDuration;

    pawns.push_back(pawn);
    cout << "Данные успешно добавлены!\n";
}

// Функция для записи данных в файл
void writeToFile(const vector<Pawn>& pawns, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cout << "Ошибка открытия файла!\n";
        return;
    }
    for (const auto& pawn : pawns) {
        outFile.write(reinterpret_cast<const char*>(&pawn), sizeof(pawn));
    }
    outFile.close();
    cout << "Данные записаны в файл!\n";
}

// Функция для чтения данных из файла
void readFromFile(vector<Pawn>& pawns, const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла!\n";
        return;
    }
    Pawn pawn;
    while (inFile.read(reinterpret_cast<char*>(&pawn), sizeof(pawn))) {
        pawns.push_back(pawn);
    }
    inFile.close();
    cout << "Данные считаны из файла!\n";
}

// Функция для вывода данных на экран
void printPawns(const vector<Pawn>& pawns) {
    for (const auto& pawn : pawns) {
        cout << "\nАнкетные данные клиента: " << pawn.data.clientName << endl;
        cout << "Наименование товара: " << pawn.data.itemName << endl;
        cout << "Оценочная стоимость: " << fixed << setprecision(2) << pawn.data.estimatedValue << endl;
        cout << "Сумма, выданная под залог: " << fixed << setprecision(2) << pawn.data.pledgedAmount << endl;
        cout << "Дата сдачи: " << pawn.data.pawnDate << endl;
        cout << "Срок хранения: " << pawn.data.storageDuration << " дней" << endl;
    }
}

// Функция для поиска товаров по наименованию
void searchPawn(const vector<Pawn>& pawns, const string& itemName) {
    bool found = false;
    for (const auto& pawn : pawns) {
        if (string(pawn.data.itemName) == itemName) {
            printPawns({ pawn });
            found = true;
        }
    }
    if (!found) {
        cout << "Товар с указанным наименованием не найден!\n";
    }
}

// Главное меню программы
int main() {
    system("chcp 1251");
    vector<Pawn> pawns;
    string filename = "pawn_data.dat";
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить товар\n";
        cout << "2. Записать данные в файл\n";
        cout << "3. Считать данные из файла\n";
        cout << "4. Показать все данные\n";
        cout << "5. Найти товар по наименованию\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputPawn(pawns);
            break;
        case 2:
            writeToFile(pawns, filename);
            break;
        case 3:
            readFromFile(pawns, filename);
            break;
        case 4:
            printPawns(pawns);
            break;
        case 5: {
            string itemName;
            cout << "Введите наименование товара: ";
            cin.ignore();
            getline(cin, itemName);
            searchPawn(pawns, itemName);
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
