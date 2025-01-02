#include <iostream>
using namespace std;

void findEvenElementsAtEvenPositions(int arr[10], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && (i + 1) % 2 == 0)
            cout << i + 1 << " "; 
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите массив: " ;
    int arr[10];

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Позиции четных элементов на четных позициях: ";
    findEvenElementsAtEvenPositions(arr, 10); 
    cout << endl; 
}
