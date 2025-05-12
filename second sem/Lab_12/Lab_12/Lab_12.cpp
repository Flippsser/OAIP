#include "Heap.h"
#include <iostream>

using namespace std;

heap::CMP cmpAAA(void* a1, void* a2) {
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else if (A2->x > A1->x)
        rc = heap::LESS;
    return rc;
#undef A2
#undef A1
}

int main() {
    system("chcp 1251");

    heap::Heap h1 = heap::create(30, cmpAAA);
    heap::Heap h2 = heap::create(30, cmpAAA);
    heap::Heap* currentHeap = &h1; 

    int choice, k, heapChoice;

    for (;;) {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1 - Показать состояние текущей кучи\n";
        cout << "2 - Добавить элемент в текущую кучу\n";
        cout << "3 - Удалить максимальный элемент из текущей кучи\n";
        cout << "4 - Удалить минимальный элемент из текущей кучи\n";
        cout << "5 - Удалить элемент по индексу из текущей кучи\n";
        cout << "6 - Объединить кучу h2 с кучей h1 (слить h2 в h1)\n";
        cout << "7 - Переключиться на другую кучу\n";
        cout << "8 - Показать содержимое обеих куч\n";
        cout << "0 - Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            cout << "\nТекущее состояние кучи " << (currentHeap == &h1 ? "h1" : "h2") << ":\n";
            currentHeap->scan(0);
            break;
        case 2: {
            AAA* a = new AAA;
            cout << "Введите целочисленный ключ для нового элемента: ";
            cin >> k;
            a->x = k;
            currentHeap->insert(a);
            cout << "Элемент " << k << " успешно добавлен в кучу "
                << (currentHeap == &h1 ? "h1" : "h2") << ".\n";
        }
              break;
        case 3:
            if (currentHeap->extractMax() != nullptr)
                cout << "Максимальный элемент удалён из кучи "
                << (currentHeap == &h1 ? "h1" : "h2") << ".\n";
            else
                cout << "Куча пуста, удалить элемент невозможно.\n";
            break;
        case 4:
            if (currentHeap->extractMin() != nullptr)
                cout << "Минимальный элемент удалён из кучи "
                << (currentHeap == &h1 ? "h1" : "h2") << ".\n";
            else
                cout << "Куча пуста, удалить элемент невозможно.\n";
            break;
        case 5:
            cout << "Введите индекс элемента для удаления (от 0 до " << currentHeap->size - 1 << "): ";
            cin >> k;
            if (currentHeap->extractI(k) != nullptr)
                cout << "Элемент с индексом " << k << " удалён из кучи "
                << (currentHeap == &h1 ? "h1" : "h2") << ".\n";
            else
                cout << "Некорректный индекс или куча пуста.\n";
            break;
        case 6:
            h1.unionHeap(h2);
            cout << "Кучи объединены: элементы из h2 добавлены в h1.\n";
            break;
        case 7:
            cout << "Выберите кучу для работы (1 - h1, 2 - h2): ";
            cin >> heapChoice;
            if (heapChoice == 1) {
                currentHeap = &h1;
                cout << "Теперь вы работаете с кучей h1.\n";
            }
            else if (heapChoice == 2) {
                currentHeap = &h2;
                cout << "Теперь вы работаете с кучей h2.\n";
            }
            else {
                cout << "Некорректный выбор кучи!\n";
            }
            break;
        case 8:
            cout << "\nСодержимое кучи h1:\n";
            h1.scan(0);
            cout << "\nСодержимое кучи h2:\n";
            h2.scan(0);
            break;
        default:
            cout << "Некорректный ввод, попробуйте снова.\n";
        }
    }

    return 0;
}
