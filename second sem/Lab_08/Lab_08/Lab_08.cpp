#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

class Queue {
private:
    queue<int> q;
    int maxSize;

public:
    Queue(int size) : maxSize(size) {}

    void enqueue(int value) {
        if (q.size() < maxSize) {
            q.push(value);
        }
        else {
            cout << "Очередь заполнена!" << endl;
        }
    }

    void dequeue() {
        if (!q.empty()) {
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

        queue<int> temp = q;
        cout << "Очередь: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void deleteFirstThree() {
        for (int i = 0; i < 3; ++i) {
            if (!q.empty()) {
                q.pop();
            }
            else {
                cout << "Очередь пуста!" << endl;
                break;
            }
        }
    }

    int getSize() {
        return q.size();
    }

    int findMax() {
        if (q.empty()) {
            cout << "Очередь пуста!" << endl;
            return numeric_limits<int>::min();
        }

        queue<int> temp = q;
        int maxElement = temp.front();
        while (!temp.empty()) {
            maxElement = max(maxElement, temp.front());
            temp.pop();
        }
        return maxElement;
    }
};

int main() {
    system("chcp 1251");
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    Queue queue(maxSize);

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Вставить элемент в очередь\n";
        cout << "2. Удалить элемент из очереди\n";
        cout << "3. Вывести очередь\n";
        cout << "4. Удалить первые три элемента\n";
        cout << "5. Вывести размер очереди\n";
        cout << "6. Найти максимальный элемент в очереди\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Введите целое число для добавления: ";
            cin >> value;
            queue.enqueue(value);
            break;
        }
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.printQueue();
            break;
        case 4:
            queue.deleteFirstThree();
            break;
        case 5:
            cout << "Размер очереди: " << queue.getSize() << endl;
            break;
        case 6:
            cout << "Максимальный элемент в очереди: " << queue.findMax() << endl;
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор, попробуйте еще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
