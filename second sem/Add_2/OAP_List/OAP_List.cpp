#include "List.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Client {
    char fio[50];
    char accountType[20];
    int accountNumber;
    double balance;
    char lastModDate[11];
};

void inputClient(Client& client) {
    cout << "Введите Ф.И.О.: ";
    cin >> client.fio;
    cout << "Введите тип счета: ";
    cin >> client.accountType;
    cout << "Введите номер счета: ";
    cin >> client.accountNumber;
    cout << "Введите сумму на счете: ";
    cin >> client.balance;
    cout << "Введите дату последнего изменения (dd.mm.yyyy): ";
    cin >> client.lastModDate;
}

void printClient(void* data) {
    Client* client = (Client*)data;
    cout << "Ф.И.О.: " << client->fio << ", ";
    cout << "Тип счета: " << client->accountType << ", ";
    cout << "Номер счета: " << client->accountNumber << ", ";
    cout << "Сумма: " << client->balance << ", ";
    cout << "Дата: " << client->lastModDate << endl;
}

Element* searchByAccount(Object& list, int accountNumber) {
    Element* temp = list.GetFirst();
    while (temp != nullptr) {
        Client* client = (Client*)temp->Data;
        if (client->accountNumber == accountNumber)
            return temp;
        temp = temp->Next;
    }
    return nullptr;
}

bool deleteByAccount(Object& list, int accountNumber) {
    Element* e = searchByAccount(list, accountNumber);
    if (e != nullptr) {
        return list.Delete(e);
    }
    return false;
}

void writeToFile(Object& list, const char* filename) {
    ofstream ofs(filename);
    if (!ofs) {
        cout << "Ошибка открытия файла для записи." << endl;
        return;
    }
    Element* temp = list.GetFirst();
    while (temp != nullptr) {
        Client* client = (Client*)temp->Data;
        ofs << client->fio << " "
            << client->accountType << " "
            << client->accountNumber << " "
            << client->balance << " "
            << client->lastModDate << "\n";
        temp = temp->Next;
    }
    ofs.close();
    cout << "Данные записаны в файл " << filename << endl;
}

void readFromFile(Object& list, const char* filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "Ошибка открытия файла для чтения." << endl;
        return;
    }
    list.DeleteList();
    while (!ifs.eof()) {
        Client* client = new Client;
        ifs >> client->fio >> client->accountType;
        if (!(ifs >> client->accountNumber))
            break;
        ifs >> client->balance >> client->lastModDate;
        list.InsertEnd(client);
    }
    ifs.close();
    cout << "Данные прочитаны из файла " << filename << endl;
}

int main() {
    system("chcp 1251");
    Object clientsList = Create();
    int choice;
    const char* filename = "clients.txt";
    do {
        cout << "\nМеню:" << endl;
        cout << "1 - Ввести нового клиента" << endl;
        cout << "2 - Вывести список клиентов" << endl;
        cout << "3 - Найти клиента по номеру счета" << endl;
        cout << "4 - Удалить клиента по номеру счета" << endl;
        cout << "5 - Записать данные в файл" << endl;
        cout << "6 - Прочитать данные из файла" << endl;
        cout << "7 - Подсчитать количество клиентов" << endl;
        cout << "8 - Удалить список" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Client* newClient = new Client;
            inputClient(*newClient);
            clientsList.InsertEnd(newClient);
            break;
        }
        case 2: {
            cout << "\nСписок клиентов:" << endl;
            clientsList.PrintList(printClient);
            break;
        }
        case 3: {
            int accNum;
            cout << "Введите номер счета для поиска: ";
            cin >> accNum;
            Element* e = searchByAccount(clientsList, accNum);
            if (e != nullptr) {
                cout << "Клиент найден:" << endl;
                printClient(e->Data);
            }
            else {
                cout << "Клиент с таким номером не найден." << endl;
            }
            break;
        }
        case 4: {
            int accNum;
            cout << "Введите номер счета для удаления: ";
            cin >> accNum;
            if (deleteByAccount(clientsList, accNum)) {
                cout << "Клиент удален." << endl;
            }
            else {
                cout << "Клиент с таким номером не найден." << endl;
            }
            break;
        }
        case 5: {
            writeToFile(clientsList, filename);
            break;
        }
        case 6: {
            readFromFile(clientsList, filename);
            break;
        }
        case 7: {
            cout << "Количество клиентов: " << clientsList.CountList() << endl;
            break;
        }
        case 8: {
            clientsList.DeleteList();
            cout << "Список очищен." << endl;
            break;
        }
        case 0: {
            cout << "Выход из программы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор, попробуйте снова." << endl;
            break;
        }
        }
    } while (choice != 0);
    clientsList.DeleteList();
    return 0;
}
