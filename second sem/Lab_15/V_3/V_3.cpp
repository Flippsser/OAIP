#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Функция пузырьковой сортировки (по убыванию)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {  // Сортировка по убыванию
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция разбиения массива для быстрой сортировки Хоара
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Опорный элемент
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {  // Сортировка по убыванию
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция быстрой сортировки Хоара
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция генерации случайного массива
vector<int> generateArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  
    }
    return arr;
}

// Функция для поиска максимального элемента и формирования массива B
vector<int> extractElements(vector<int>& A) {
    int maxIndex = 0;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] > A[maxIndex]) {
            maxIndex = i;  
        }
    }

    vector<int> B;
    for (int i = maxIndex + 1; i < A.size(); i++) {
        if (i % 2 == 1) {  // Проверяем, что индекс нечётный
            B.push_back(A[i]);
        }
    }

    return B;
}

int main() {
    system("chcp 1251");
    srand(time(0));  // Инициализация генератора случайных чисел

    int size;
    cout << "Введите размер массива A: ";
    cin >> size;

    vector<int> A = generateArray(size);

    // Вывод исходного массива
    cout << "Исходный массив A: ";
    for (int num : A) cout << num << " ";
    cout << endl;

    // Формируем массив B
    vector<int> B = extractElements(A);

    // Вывод массива B
    cout << "Массив B (элементы правее максимального с нечётным индексом): ";
    for (int num : B) cout << num << " ";
    cout << endl;

    // Сортировка пузырьком + замер времени
    auto startBubble = chrono::high_resolution_clock::now();
    bubbleSort(B);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> bubbleTime = endBubble - startBubble;

    // Вывод отсортированного массива пузырьком
    cout << "B после пузырьковой сортировки: ";
    for (int num : B) cout << num << " ";
    cout << endl;
    cout << "Время пузырьковой сортировки: " << bubbleTime.count() << " мс" << endl;

    // Восстанавливаем массив B перед следующей сортировкой
    B = extractElements(A);

    // Быстрая сортировка Хоара + замер времени
    auto startQuick = chrono::high_resolution_clock::now();
    quickSort(B, 0, B.size() - 1);
    auto endQuick = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> quickTime = endQuick - startQuick;

    // Вывод отсортированного массива Хоара
    cout << "B после быстрой сортировки Хоара: ";
    for (int num : B) cout << num << " ";
    cout << endl;
    cout << "Время быстрой сортировки Хоара: " << quickTime.count() << " мс" << endl;

    return 0;
}
