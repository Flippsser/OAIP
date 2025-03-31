#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
int arrh, arrm, deph, depm;
enum DaysOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct Time {
    unsigned int hours : 5;
    unsigned int minutes : 6;
};

struct Train {
    int number;
    string destination;
    DaysOfWeek days;
    Time arrival;
    Time departure;
};

string dayToString(DaysOfWeek day) {
    switch (day) {
    case MONDAY: return "Понедельник";
    case TUESDAY: return "Вторник";
    case WEDNESDAY: return "Среда";
    case THURSDAY: return "Четверг";
    case FRIDAY: return "Пятница";
    case SATURDAY: return "Суббота";
    case SUNDAY: return "Воскресенье";
    default: return "Неизвестный день";
    }
}

Train inputTrain() {
    Train train = {};
    cout << "Введите номер поезда: ";
    cin >> train.number;
    cout << "Введите пункт назначения: ";
    cin.ignore();
    getline(cin, train.destination);

    int dayInput;
    cout << "Введите день следования (0 - Понедельник, 1 - Вторник, ..., 6 - Воскресенье): ";
    cin >> dayInput;
    train.days = static_cast<DaysOfWeek>(dayInput);

    cin >> arrh >> arrm;
    train.arrival.hours = arrh;
    train.arrival.minutes = arrm;
    cout << "Введите время отправления (часы и минуты через enter): ";
    cin >> deph >> depm;
    train.departure.hours = deph;
    train.departure.minutes = depm;

    return train;
}

void printTrain(const Train& train) {
    cout << "Номер поезда: " << train.number << endl;
    cout << "Пункт назначения: " << train.destination << endl;
    cout << "День следования: " << dayToString(train.days) << endl;
    cout << "Время прибытия: " << setw(2) << setfill('0') << train.arrival.hours << ":"
        << setw(2) << setfill('0') << train.arrival.minutes << endl;
    cout << "Время отправления: " << setw(2) << setfill('0') << train.departure.hours << ":"
        << setw(2) << setfill('0') << train.departure.minutes << endl;
}

void searchByDestination(const vector<Train>& trains, const string& destination) {
    bool found = false;
    for (const auto& train : trains) {
        if (train.destination == destination) {
            printTrain(train);
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Поезда с указанным пунктом назначения не найдены." << endl;
    }
}

void deleteTrain(vector<Train>& trains, int number) {
    auto it = remove_if(trains.begin(), trains.end(), [&number](const Train& train) {
        return train.number == number;
        });
    if (it != trains.end()) {
        trains.erase(it, trains.end());
        cout << "Поезд удален." << endl;
    }
    else {
        cout << "Поезд с указанным номером не найден." << endl;
    }
}

void printAllTrains(const vector<Train>& trains) {
    if (trains.empty()) {
        cout << "Список поездов пуст." << endl;
        return;
    }
    for (const auto& train : trains) {
        printTrain(train);
        cout << endl;
    }
}

int main() {
    system("chcp 1251");
    vector<Train> trains;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить поезд\n";
        cout << "2. Показать все поезда\n";
        cout << "3. Найти поезд по пункту назначения\n";
        cout << "4. Удалить поезд\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            trains.push_back(inputTrain());
            break;
        case 2:
            printAllTrains(trains);
            break;
        case 3: {
            string destination;
            cout << "Введите пункт назначения для поиска: ";
            cin.ignore();
            getline(cin, destination);
            searchByDestination(trains, destination);
            break;
        }
        case 4: {
            int number;
            cout << "Введите номер поезда для удаления: ";
            cin >> number;
            deleteTrain(trains, number);
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
