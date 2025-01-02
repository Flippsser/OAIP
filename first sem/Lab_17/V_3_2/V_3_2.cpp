#include <iostream>
using namespace std;

void processMatrix(int** matrix, int rows, int cols) {
    int rowSum = 0;
    bool positiveRowFound = false;

    for (int i = 0; i < rows; i++) {
        bool allPositive = true;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] <= 0) {
                allPositive = false;
                break;
            }
        }
        if (allPositive) {
            positiveRowFound = true;
            for (int j = 0; j < cols; j++) {
                rowSum += matrix[i][j];
            }
            cout << "Сумма элементов положительной строки (" << i + 1 << "): " << rowSum << endl;
            break;
        }
    }

    if (positiveRowFound) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] -= rowSum;
            }
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Rus");
    int rows, cols;
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> rows >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Исходная матрица: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    processMatrix(matrix, rows, cols);

    cout << "Матрица после обработки: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
