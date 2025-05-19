#include <iostream>
#include <vector>
using namespace std;

vector<int> countingSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> sorted(n);
    vector<int> count(n, 0);

    // Подсчитываем, сколько чисел меньше каждого элемента
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] < arr[i]) count[i]++;
        }
    }

    // Формируем отсортированный массив
    for (int i = 0; i < n; i++) {
        sorted[count[i]] = arr[i];
    }

    return sorted;
}

int main() {
    vector<int> arr = { 20, -5, 10, 8, 7 };
    vector<int> sortedArr = countingSort(arr);
    for (int num : sortedArr) cout << num << " ";
    return 0;
}
