#include <iostream>
#include <fstream>
using namespace std;

struct list {
    int value;
    list* next;
};

void insert(list*& p, int value);
void remove(list*& p, int value);
list* search(list* p, int value);
void printList(list* p);
void toFile(list* p);
void fromFile(list*& p);
int sumPositiveMultiplesOfFive(list* p);
void deleteList(list*& p);
void menu();

int main() {
    setlocale(LC_CTYPE, "Russian");
    list* first = nullptr;
    int choice, value;
    menu();
    cout << " ? ";
    cin >> choice;
    while (choice != 7) {
        switch (choice) {
        case 1:
            cout << "Введите число: ";
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:
            cout << "Введите число для удаления: ";
            cin >> value;
            remove(first, value);
            printList(first);
            break;
        case 3:
            cout << "Введите число для поиска: ";
            cin >> value;
            if (search(first, value)) {
                cout << "Элемент найден!" << endl;
            }
            else {
                cout << "Элемент не найден!" << endl;
            }
            break;
        case 4:
            printList(first);
            break;
        case 5:
            toFile(first);
            break;
        case 6:
            fromFile(first);
            break;



        case 8: {
            int sum = sumPositiveMultiplesOfFive(first);
            if (sum == 0) {
                cout << "Положительных элементов, кратных 5, нет!" << endl;
            }
            else {
                cout << "Сумма положительных элементов, кратных 5: " << sum << endl;
            }
            break;
        }
        default:
            cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }


    deleteList(first);
    return 0;
}

void insert(list*& p, int value) {
    list* newP = new list;
    if (newP != NULL) {
        newP->value = value;
        newP->next = p;
        p = newP;
    }
    else {
        cout << "Операция добавления не выполнена" << endl;
    }
}

void remove(list*& p, int value) {
    list* current = p;
    list* previous = nullptr;

    while (current != nullptr && current->value != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Элемент не найден" << endl;
        return;
    }

    if (previous == nullptr) {
        p = current->next;
    }
    else {
        previous->next = current->next;
    }

    delete current;
}

list* search(list* p, int value) {
    while (p != nullptr) {
        if (p->value == value) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void printList(list* p) {
    if (p == nullptr) {
        cout << "Список пуст" << endl;
    }
    else {
        cout << "Список:" << endl;
        while (p != nullptr) {
            cout << "-->" << p->value;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(list* p) {
    ofstream frm("mList.dat", ios::binary);
    if (frm.fail()) {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (p) {
        frm.write((char*)&p->value, sizeof(int));
        p = p->next;
    }
    frm.close();
    cout << "Список записан в файл mList.dat\n";
}

void fromFile(list*& p) {
    ifstream frm("mList.dat", ios::binary);
    if (frm.fail()) {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    int value;
    while (frm.read((char*)&value, sizeof(int))) {
        insert(p, value);
    }
    frm.close();
    cout << "\nСписок считан из файла mList.dat\n";
}







int sumPositiveMultiplesOfFive(list* p) {
    int sum = 0;
    while (p != nullptr) {
        if (p->value > 0 && p->value % 5 == 0) { // Проверка на положительность и кратность 5
            sum += p->value;
        }
        p = p->next;
    }
    return sum;
}

void deleteList(list*& p) {
    while (p != nullptr) {
        list* temp = p;
        p = p->next;
        delete temp;
    }
}

void menu() {
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Поиск числа" << endl;
    cout << " 4 - Вывод списка" << endl;
    cout << " 5 - Запись списка в файл" << endl;
    cout << " 6 - Чтение списка из файла" << endl;
    cout << " 7 - Выход" << endl;
    cout << "8 - Найти сумму положительных элементов, кратных 5" << endl;
}