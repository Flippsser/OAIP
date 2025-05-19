#include "Hash.h"
#include <iostream>
#include <chrono> 
#include <iomanip> 
using namespace std;

HashMethod selectedMethod;

struct AAA {
    int key;
    char* mas;
    AAA(int k, char* z) : key(k), mas(z) {}
    AAA() {}
};

int key(void* d) {
    return ((AAA*)d)->key;
}

void AAA_print(void* d) {
    cout << "Ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

void chooseHashMethod() {
    int method;
    cout << "Выберите метод хеширования:\n";
    cout << "1 - Мультипликативное\n2 - Универсальное\n3 - Модульное\nВаш выбор: ";
    cin >> method;
    if (method == 1)
        selectedMethod = MULTIPLICATIVE;
    else if (method == 2)
        selectedMethod = UNIVERSAL;
    else
        selectedMethod = MODULAR;
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "rus");
    int size, choice, k;

    chooseHashMethod();
    cout << "Введите размер хеш-таблицы: ";
    cin >> size;

    Object H = create(size, key);

    while (true) {
        cout << "\n1 - Вывод хеш-таблицы\n2 - Добавление элемента\n3 - Удаление элемента\n4 - Поиск элемента\n5 - Исследование времени поиска\n0 - Выход\nВыбор: ";
        cin >> choice;
        if (choice == 0)
            break;

        switch (choice) {
        case 1:
            H.scan(AAA_print);
            break;
        case 2: {
            AAA* a = new AAA;
            char* str = new char[20];
            cout << "Введите ключ: ";
            cin >> k;
            a->key = k;
            cout << "Введите строку: ";
            cin >> str;
            a->mas = str;
            if (H.N == H.size)
                cout << "Таблица заполнена" << endl;
            else
                H.insert(a);
        } break;
        case 3: {
            cout << "Введите ключ для удаления: ";
            cin >> k;
            H.deleteByKey(k);
        } break;
        case 4: {
            cout << "Введите ключ для поиска: ";
            cin >> k;
            auto start = chrono::high_resolution_clock::now();
            void* found = H.search(k);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> elapsed = end - start;
            if (found == NULL)
                cout << "Элемент не найден" << endl;
            else
                AAA_print(found);
            cout << fixed << setprecision(6) << "Время поиска: " << elapsed.count() << " мс" << endl;
        } break;
        case 5: {
            cout << "Введите количество случайных элементов для теста: ";
            int numTests;
            cin >> numTests;

            // Заполнение таблицы случайными элементами
            for (int i = 0; i < numTests; ++i) {
                AAA* a = new AAA(i, new char[20]);
                H.insert(a);
            }

            cout << "Исследование времени поиска..." << endl;
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < numTests; ++i) {
                H.search(i);
            }
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> elapsed = end - start;
            cout << fixed << setprecision(6) << "Среднее время поиска: " << (elapsed.count() / numTests) << " мс" << endl;
        } break;
        default:
            cout << "Неверный выбор" << endl;
        }
    }
    return 0;
}
