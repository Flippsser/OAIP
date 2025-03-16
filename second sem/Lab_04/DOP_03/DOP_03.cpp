#include <iostream>
#include <string>
using namespace std;

struct Sanatorium {
    string name;
    string location;
    string profile;
    int voucherCount;
};

void sortSanatoriums(Sanatorium sanatoriums[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (sanatoriums[i].profile > sanatoriums[j].profile ||
                (sanatoriums[i].profile == sanatoriums[j].profile && sanatoriums[i].name > sanatoriums[j].name)) {
                Sanatorium temp = sanatoriums[i];
                sanatoriums[i] = sanatoriums[j];
                sanatoriums[j] = temp;
            }
        }
    }
}

void groupAndDisplay(const Sanatorium sanatoriums[], int size) {
    string currentProfile = "";

    for (int i = 0; i < size; ++i) {
        if (sanatoriums[i].profile != currentProfile) {
            currentProfile = sanatoriums[i].profile;
            cout << "Лечебный профиль: " << currentProfile << endl;
            cout << "--------------------------------" << endl;
        }
        cout << "Название: " << sanatoriums[i].name
            << ", Место: " << sanatoriums[i].location
            << ", Количество путевок: " << sanatoriums[i].voucherCount << endl;
    }
}

void searchSanatoriums(const Sanatorium sanatoriums[], int size, const string& profile) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (sanatoriums[i].profile == profile) {
            cout << "Название: " << sanatoriums[i].name
                << ", Место: " << sanatoriums[i].location
                << ", Количество путевок: " << sanatoriums[i].voucherCount << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Санатории с профилем \"" << profile << "\" не найдены." << endl;
    }
}

int main() {
    system("chcp 1251");
    const int size = 6;
    Sanatorium sanatoriums[size] = {
        {"Солнечный берег", "Минск", "Кардиология", 15},
        {"Зеленая роща", "Гродно", "Неврология", 10},
        {"Лесная сказка", "Могилев", "Кардиология", 12},
        {"Озеро надежды", "Витебск", "Гастроэнтерология", 20},
        {"Горное озеро", "Гомель", "Неврология", 8},
        {"Морской бриз", "Брест", "Гастроэнтерология", 18}
    };

    sortSanatoriums(sanatoriums, size);

    cout << "Санатории, сгруппированные по лечебным профилям:" << endl;
    groupAndDisplay(sanatoriums, size);

    string searchProfile;
    cout << "Введите профиль для поиска: ";
    cin >> searchProfile;
    cout << "Результаты поиска:" << endl;
    searchSanatoriums(sanatoriums, size, searchProfile);

    return 0;
}
