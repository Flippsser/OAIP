#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_CLIENTS = 100;

struct BankClient {
    string fullName;
    string accountType;
    string accountNumber;
    double balance;
    string lastChangeDate;
};

void inputClient(BankClient& client) {
    cout << "Введите Ф.И.О.: ";
    getline(cin, client.fullName);
    cout << "Введите тип счета: ";
    getline(cin, client.accountType);
    cout << "Введите номер счета: ";
    getline(cin, client.accountNumber);
    cout << "Введите баланс: ";
    cin >> client.balance;
    cin.ignore();  
    cout << "Введите дату последнего изменения: ";
    getline(cin, client.lastChangeDate);
}

void displayClients(const BankClient clients[], int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Ф.И.О.: " << clients[i].fullName << endl;
        cout << "Тип счета: " << clients[i].accountType << endl;
        cout << "Номер счета: " << clients[i].accountNumber << endl;
        cout << "Баланс: " << clients[i].balance << endl;
        cout << "Дата последнего изменения: " << clients[i].lastChangeDate << endl;
        cout << "----------------------------" << endl;
    }
}

void deleteClient(BankClient clients[], int& count, const string& accountNumber) {
    for (int i = 0; i < count; ++i) {
        if (clients[i].accountNumber == accountNumber) {
            for (int j = i; j < count - 1; ++j) {
                clients[j] = clients[j + 1];
            }
            --count;
            cout << "Клиент с номером счета " << accountNumber << " удален." << endl;
            return;
        }
    }
    cout << "Клиент с номером счета " << accountNumber << " не найден." << endl;
}

void searchClient(const BankClient clients[], int count, const string& accountNumber) {
    for (int i = 0; i < count; ++i) {
        if (clients[i].accountNumber == accountNumber) {
            cout << "Ф.И.О.: " << clients[i].fullName << endl;
            cout << "Тип счета: " << clients[i].accountType << endl;
            cout << "Номер счета: " << clients[i].accountNumber << endl;
            cout << "Баланс: " << clients[i].balance << endl;
            cout << "Дата последнего изменения: " << clients[i].lastChangeDate << endl;
            return;
        }
    }
    cout << "Клиент с номером счета " << accountNumber << " не найден." << endl;
}

void writeToFile(const BankClient clients[], int count, const string& filename) {
    ofstream outFile(filename);
    for (int i = 0; i < count; ++i) {
        outFile << clients[i].fullName << endl;
        outFile << clients[i].accountType << endl;
        outFile << clients[i].accountNumber << endl;
        outFile << clients[i].balance << endl;
        outFile << clients[i].lastChangeDate << endl;
    }
    cout << "Информация записана в файл " << filename << endl;
}

void readFromFile(BankClient clients[], int& count, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    count = 0;
    while (count < MAX_CLIENTS && getline(inFile, clients[count].fullName)) {
        getline(inFile, clients[count].accountType);
        getline(inFile, clients[count].accountNumber);
        inFile >> clients[count].balance;
        inFile.ignore(); 
        getline(inFile, clients[count].lastChangeDate);
        ++count;
    }
    cout << "Информация прочитана из файла " << filename << endl;
}

void displayMenu() {
    cout << "Выберите действие:" << endl;
    cout << "1. Добавить клиента" << endl;
    cout << "2. Показать всех клиентов" << endl;
    cout << "3. Удалить клиента" << endl;
    cout << "4. Найти клиента" << endl;
    cout << "5. Записать информацию в файл" << endl;
    cout << "6. Прочитать информацию из файла" << endl;
    cout << "0. Выйти" << endl;
}

int main() {
    system("chcp 1251");
    BankClient clients[MAX_CLIENTS];
    int count = 0;
    int choice;
    string accountNumber;
    string filename = "clients.txt";

    while (true) {
        cout << endl;
        displayMenu();
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            if (count < MAX_CLIENTS) {
                inputClient(clients[count]);
                ++count;
            }
            else {
                cout << "Достигнут предел количества клиентов." << endl;
            }
            break;
        case 2:
            displayClients(clients, count);
            break;
        case 3:
            cout << "Введите номер счета для удаления: ";
            getline(cin, accountNumber);
            deleteClient(clients, count, accountNumber);
            break;
        case 4:
            cout << "Введите номер счета для поиска: ";
            getline(cin, accountNumber);
            searchClient(clients, count, accountNumber);
            break;
        case 5:
            writeToFile(clients, count, filename);
            break;
        case 6:
            readFromFile(clients, count, filename);
            break;
        case 0:
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте ещё раз." << endl;
        }
    }
}
