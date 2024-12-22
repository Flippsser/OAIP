#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int n, m, k;
    cout << "Введите количество строк (n): ";
    cin >> n;
    cout << "Введите количество столбцов (m): ";
    cin >> m;
    cout << "Введите номер строки (k): ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Неверный номер строки k." << endl;
        return 0;
    }

    srand(time(0));

    int** A = new int* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[m];
    }

    cout << "Элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = rand() % 100;
            cout << *(*(A + i) + j) << " ";
        }
        cout << endl;
    }

    int f = 0;
    for (int j = 1; j < m; ++j) {
        if (*(*(A + k - 1) + j) > *(*(A + k - 1) + j - 1)) {
            f = 1;
            break;
        }
    }

    if (f == 0) {
        cout << "Все элементы " << k << "-ой строки упорядочены по убыванию." << endl;
    }
    else {
        cout << "Элементы " << k << "-ой строки не упорядочены по убыванию." << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
