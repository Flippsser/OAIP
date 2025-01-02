#include <iostream>
using namespace std;

int sumBetweenZeros(int* arr, int size) {
    int firstZeroIndex = -1;
    int lastZeroIndex = -1;
    int sum = 0;

    // Найти индексы первого и последнего нулевых элементов
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            }
            lastZeroIndex = i;
        }
    }

    // Если нет двух нулевых элементов, вернуть 0
    if (firstZeroIndex == -1 || lastZeroIndex == -1 || firstZeroIndex == lastZeroIndex) {
        return 0;
    }

    // Суммировать элементы между первым и последним нулевыми элементами
    for (int i = firstZeroIndex + 1; i < lastZeroIndex; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    setlocale(LC_CTYPE, "Rus");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = sumBetweenZeros(arr, n);
    cout << "Сумма элементов между первым и последним нулевыми элементами: " << sum << endl;

    delete[] arr;
    return 0;
}
