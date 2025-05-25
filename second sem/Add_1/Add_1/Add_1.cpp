#include <iostream>
using namespace std;

struct Item {
    int data;
    Item* next;
};

Item* head = nullptr;
Item* tail = nullptr;

bool isNull() {
    return (head == nullptr);
}

void deletFirst() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
    }
    else {
        Item* p = head;
        head = head->next;
        delete p;
    }
}

void printQueue() {
    if (isNull()) {
        cout << "Очередь пуста" << endl;
        return;
    }
    Item* p = head;
    cout << "Очередь = ";
    while (p != nullptr) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Вставка элемента по приоритету (минимальное значение, LIFO)
void insertMinLIFO(int x) {
    Item* p = new Item;
    p->data = x;
    p->next = nullptr;

    if (isNull() || x < head->data) {
        p->next = head;
        head = p;
    }
    else {
        Item* temp = head;
        while (temp->next != nullptr && temp->next->data < x) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
}

// Вставка элемента по приоритету (максимальное значение, FIFO)
void insertMaxFIFO(int x) {
    Item* p = new Item;
    p->data = x;
    p->next = nullptr;

    if (isNull() || x > head->data) {
        p->next = head;
        head = p;
    }
    else {
        Item* temp = head;
        while (temp->next != nullptr && temp->next->data > x) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
    }
}

// Вставка элемента по приоритету (минимальное значение, LIFO, удаление с конца)
void insertMinLIFOEnd(int x) {
    Item* p = new Item;
    p->data = x;
    p->next = nullptr;

    if (isNull()) {
        head = tail = p;
    }
    else {
        if (x < head->data) {
            p->next = head;
            head = p;
        }
        else {
            Item* temp = head;
            while (temp->next != nullptr && temp->next->data < x) {
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
            if (p->next == nullptr) tail = p;
        }
    }
}

// Вставка элемента по приоритету (максимальное значение, FIFO, удаление с конца)
void insertMaxFIFOEnd(int x) {
    Item* p = new Item;
    p->data = x;
    p->next = nullptr;

    if (isNull()) {
        head = tail = p;
    }
    else {
        if (x > head->data) {
            p->next = head;
            head = p;
        }
        else {
            Item* temp = head;
            while (temp->next != nullptr && temp->next->data > x) {
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
            if (p->next == nullptr) tail = p;
        }
    }
}

// Очистка всей очереди
void clrQueue() {
    while (!isNull()) deletFirst();
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice, z, queueType;

    cout << "Выберите тип очереди:\n";
    cout << "1 - Минимальное значение, LIFO\n";
    cout << "2 - Максимальное значение, FIFO\n";
    cout << "3 - Минимальное значение, LIFO (удаление с конца)\n";
    cout << "4 - Максимальное значение, FIFO (удаление с конца)\n";
    cout << "Введите номер: ";
    cin >> queueType;

    while (true) {
        cout << "\n1 - Добавить элемент\n";
        cout << "2 - Удалить элемент\n";
        cout << "3 - Вывести элементы\n";
        cout << "4 - Очистить очередь\n";
        cout << "0 - Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент: ";
            cin >> z;
            switch (queueType) {
            case 1: insertMinLIFO(z); break;
            case 2: insertMaxFIFO(z); break;
            case 3: insertMinLIFOEnd(z); break;
            case 4: insertMaxFIFOEnd(z); break;
            }
            printQueue();
            break;
        case 2:
            deletFirst();
            printQueue();
            break;
        case 3:
            printQueue();
            break;
        case 4:
            clrQueue();
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор" << endl;
        }
    }
}
