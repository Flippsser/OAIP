#include <iostream>
#include <fstream>

using namespace std;

void generateNumbers(int len, int index, int* arr, int maxDigit, ofstream& fout) {
    if (index == len) {
        for (int i = 0; i < len; i++)
            fout << arr[i];
        fout << "\n";
        return;
    }
    for (int d = 0; d <= maxDigit; d++) {
        arr[index] = d;
        generateNumbers(len, index + 1, arr, maxDigit, fout);
    }
}

int main() {
    int A;
    cin >> A;
    int* arr = new int[A];
    ofstream fout("output.txt");
    if (!fout) {
        cerr << "Ошибка открытия файла.\n";
        delete[] arr;
        return 1;
    }
    generateNumbers(A, 0, arr, A, fout);
    fout.close();
    delete[] arr;
    return 0;
}
