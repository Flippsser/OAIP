#include <iostream>
#include <queue>

using namespace std;

class CharQueue {
private:
    queue<char> q;
    int maxSize;

public:
    CharQueue(int size) : maxSize(size) {}

    void enqueue(char value) {
        if (q.size() < maxSize) {
            q.push(value);
        }
        else {
            cout << "Очередь заполнена!" << endl;
        }
    }

    void dequeue() {
        if (!q.empty()) {
            cout << "Удалено: " << q.front() << endl;
            q.pop();
        }
        else {
            cout << "Очередь пуста!" << endl;
        }
    }

    void printQueue() {
        if (q.empty()) {
            cout << "Очередь пуста!" << endl;
            return;
        }
        queue<char> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    system("chcp 1251");
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    CharQueue queue(maxSize);
    int count = 0;

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Ввести символ в очередь" << endl;
        cout << "2. Удалить элемент из очереди" << endl;
        cout << "3. Вывести очередь" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            char value;
            cout << "Введите символ: ";
            cin >> value;
            queue.enqueue(value);
            count++;
            if (count >= 5) {
                queue.dequeue();
                count--;
            }
            break;
        }
        case 2:
            queue.dequeue();
            count--;
            break;
        case 3:
            queue.printQueue();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            return 0;
        default:
            cout << "Неверный выбор, попробуйте еще раз." << endl;
        }
    }
}
