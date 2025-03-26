#include <iostream>
#include <string>
using namespace std;

struct TRAIN {
    string destination;
    int trainNumber;
    string departureTime;
};

void sortTrainsByDestination(TRAIN trains[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (trains[i].destination > trains[j].destination) {
                TRAIN temp = trains[i];
                trains[i] = trains[j];
                trains[j] = temp;
            }
        }
    }
}

void displayTrainsAfterTime(const TRAIN trains[], int size, const string& time) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (trains[i].departureTime > time) {
            cout << "Пункт назначения: " << trains[i].destination
                << ", Номер поезда: " << trains[i].trainNumber
                << ", Время отправления: " << trains[i].departureTime << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Поезда, отправляющиеся после " << time << ", отсутствуют." << endl;
    }
}

int main() {
    system("chcp 1251");
    const int size = 3;
    TRAIN trains[size];

    cout << "Введите данные для 8 поездов (пункт назначения, номер поезда, время отправления):" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Поезд " << i + 1 << ":" << endl;
        cout << "Пункт назначения: ";
        cin >> trains[i].destination;
        cout << "Номер поезда: ";
        cin >> trains[i].trainNumber;
        cout << "Время отправления (формат ЧЧMM): ";
        cin >> trains[i].departureTime;
    }

    sortTrainsByDestination(trains, size);

    string time;
    cout << "Введите время (формат ЧЧMM): ";
    cin >> time;

    cout << "Поезда, отправляющиеся после " << time << ":" << endl;
    displayTrainsAfterTime(trains, size, time);

    return 0;
}
