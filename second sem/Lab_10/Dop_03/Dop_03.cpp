#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void permute(vector<int>& arr, int l, int r) {
    if (l == r) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(arr[l], arr[i]);        
            permute(arr, l + 1, r);         
            swap(arr[l], arr[i]);         
        }
    }
}

int main() {
    system("chcp 1251");
    vector<int> numbers(5);

    cout << "Введите 5 натуральных чисел:\n";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    cout << "\nВсе перестановки введённых чисел:\n";
    permute(numbers, 0, numbers.size() - 1);

    return 0;
}
