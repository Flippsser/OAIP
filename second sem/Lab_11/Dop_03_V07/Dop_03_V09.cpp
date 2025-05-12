#include <iostream>
#include <string>
#include <limits> 
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

int countNodesWithDataValue(Node* p1, int k) {
    if (!p1)
        return 0;
    int count = (p1->data == to_string(k)) ? 1 : 0;
    count += countNodesWithDataValue(p1->left, k);
    count += countNodesWithDataValue(p1->right, k);
    return count;
}

int main() {
    system("chcp 1251");
    Node* p1 = nullptr; 
    int choice;

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Вставить узел" << endl;
        cout << "2. Подсчитать количество вершин, значение ячейки которых равно k" << endl;
        cout << "3. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 1) {
            int key;
            string data;
            cout << "Введите ключ (целое число): ";
            cin >> key;
            cout << "Введите значение ячейки: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, data);
            p1 = insert(p1, key, data);
            cout << "Узел добавлен." << endl;
        }
        else if (choice == 2) {
            int k;
            cout << "Введите число k: ";
            cin >> k;
            int count = countNodesWithDataValue(p1, k);
            cout << "Количество узлов, значение ячейки которых равно " << k << ": " << count << endl;
        }
        else if (choice == 3) {
            cout << "Завершение работы программы." << endl;
            break;
        }
        else {
            cout << "Некорректный выбор. Повторите попытку." << endl;
        }
    }

    return 0;
}
