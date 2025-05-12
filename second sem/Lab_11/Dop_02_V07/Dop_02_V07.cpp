#include <iostream>
#include <string>

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

int countLeaves(Node* p1) {
    if (!p1) return 0;
    if (!p1->left && !p1->right) return 1;
    return countLeaves(p1->left) + countLeaves(p1->right);
}

void printTree(Node* root, int depth = 0) {
    if (root) {
        printTree(root->right, depth + 1); 
        for (int i = 0; i < depth; ++i) cout << "    "; 
        cout << root->key << " (" << root->data << ")" << endl;
        printTree(root->left, depth + 1); 
    }
}

int main() {
    system("chcp 1251");
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Вставить узел" << endl;
        cout << "2. Подсчитать количество листьев" << endl;
        cout << "3. Вывести дерево" << endl;
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
            Node* p1 = root;
            int leafCount = countLeaves(p1);
            cout << "Количество листьев в дереве: " << leafCount << endl;
        }
        else if (choice == 3) {
            cout << "Структура дерева:" << endl;
            printTree(root);
        }
        else if (choice == 4) {
            cout << "Завершение работы программы." << endl;
            break;
        }
        else {
            cout << "Некорректный выбор. Повторите попытку." << endl;
        }
    }

    return 0;
}
