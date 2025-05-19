#include "Hash_Chain.h"
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

// Структура для хранения данных о школе.
struct School {
    int schoolNumber;
    char* directorName;

    School(int num, char* name) {
        schoolNumber = num;
        directorName = name;
    }

    School() {
        schoolNumber = 0;
        directorName = nullptr;
    }
};

// Функция хеширования: возвращает schoolNumber.
int hashFunction(void* d) {
    return ((School*)d)->schoolNumber;
}

// Функция для вывода информации об элементе. (Можно отметить как static, если не требуется внешне.)
static void printSchool(const listx::Element* e) {
    cout << ((School*)e->data)->schoolNumber << " - "
        << ((School*)e->data)->directorName << " / ";
}

int main() {
    setlocale(LC_ALL, "rus");
    int current_size;
    cout << "Введите размер хеш-таблицы: ";
    cin >> current_size;

    // Создаём хеш-таблицу с заданным размером и функцией хеширования.
    hashTC::Object H = hashTC::create(current_size, hashFunction);

    int choice, schoolNum;
    while (true) {
        cout << "\n1 - Вывод хеш-таблицы\n"
            << "2 - Добавление элемента\n"
            << "3 - Удаление элемента\n"
            << "4 - Поиск элемента\n"
            << "5 - Измерение времени поиска\n"
            << "0 - Выход\n"
            << "Выбор: ";
        cin >> choice;
        if (choice == 0)
            break;

        switch (choice) {
        case 1:
            H.Scan();
            break;
        case 2: {
            School* s = new School;
            char* name = new char[20];
            cout << "Введите номер школы: ";
            cin >> schoolNum;
            s->schoolNumber = schoolNum;
            cout << "Введите фамилию директора: ";
            cin >> name;
            s->directorName = name;
            H.insert(s);
        } break;
        case 3: {
            School* s = new School;
            cout << "Введите номер школы для удаления: ";
            cin >> schoolNum;
            s->schoolNumber = schoolNum;
            H.deleteByData(s);
        } break;
        case 4: {
            School* s = new School;
            cout << "Введите номер школы для поиска: ";
            cin >> schoolNum;
            s->schoolNumber = schoolNum;
            auto start = chrono::high_resolution_clock::now();
            listx::Element* found = H.search(s);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> elapsed = end - start;
            if (found == nullptr)
                cout << "Элемент не найден" << endl;
            else {
                cout << "Найден: ";
                printSchool(found);
                cout << endl;
            }
            cout << fixed << setprecision(6)
                << "Время поиска: " << elapsed.count() << " мс" << endl;
        } break;
        case 5: {
            // Для измерения времени поиска можно протестировать несколько запросов.
            cout << "Введите количество тестовых поисков: ";
            int numTests;
            cin >> numTests;
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < numTests; i++) {
                // Выполняем поиск по ключу i (пример; в реальном случае можно генерировать случайные ключи)
                School temp;
                temp.schoolNumber = i;
                H.search(&temp);
            }
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> elapsed = end - start;
            cout << fixed << setprecision(6)
                << "Среднее время поиска: " << (elapsed.count() / numTests) << " мс" << endl;
        } break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    }
    return 0;
}
