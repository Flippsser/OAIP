#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;

struct Node {
    int key;
    string data;
    Node* left;
    Node* right;
};

Node* createNode(int key, const string& data) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int key, const string& data) {
    if (!root) {
        return createNode(key, data);
    }
    if (key < root->key)
        root->left = insert(root->left, key, data);
    else if (key > root->key)
        root->right = insert(root->right, key, data);
    return root;
}

void displayTree(Node* root, int space = 0, int distance = 5) {
    if (root == nullptr) return;

    space += distance;

    displayTree(root->right, space);

    cout << endl;
    for (int i = distance; i < space; i++) {
        cout << " ";
    }
    cout << root->key << " (" << root->data << ")";

    displayTree(root->left, space);
}

int countLeftChildren(Node* root) {
    if (!root) return 0;
    int count = 0;
    if (root->left) {
        count += 1;
        count += countLeftChildren(root->left);
    }
    count += countLeftChildren(root->right);
    return count;
}

int main() {
    system("chcp 1251");
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Вставить узел" << endl;
        cout << "2. Вывод дерева" << endl;
        cout << "3. Подсчитать количество левых дочерних вершин" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 1) {
            int key;
            string data;
            cout << "Введите ключ (целое число): ";
            cin >> key;
            cout << "Введите строку: ";
            cin.ignore();
            getline(cin, data);
            root = insert(root, key, data);
            cout << "Узел добавлен." << endl;
        }
        else if (choice == 2) {
            cout << "Дерево:" << endl;
            if (root == nullptr) {
                cout << "Дерево пустое." << endl;
            }
            else {
                displayTree(root);
                cout << endl;
            }
        }
        else if (choice == 3) {
            int count = countLeftChildren(root);
            cout << "Количество левых дочерних вершин: " << count << endl;
        }
        else if (choice == 4) {
            cout << "Завершение работы программы." << endl;
            break;
        }
        else {
            cout << "Некорректный выбор. Повторите." << endl;
        }
    }

    return 0;
}
