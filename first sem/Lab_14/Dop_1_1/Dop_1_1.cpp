#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_VALUE = 10;
const int MIN_VALUE = -10;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    int matrix[20][20];

    srand(time(0));

    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i + n][j + n];
            matrix[i + n][j + n] = temp;
        }
    }

    for (int i = n; i < 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i - n][j + n];
            matrix[i - n][j + n] = temp;
        }
    }

    cout << "\nМатрица после перестановки блоков:" << endl;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
