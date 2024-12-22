#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 4;
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }


    srand(time(0));


    cout << "Матрица 4x4:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 21 - 10;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int sumOddMin = 0, sumEvenMax = 0;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            int maxElement = matrix[i][0];
            for (int j = 1; j < size; j++)
            {
                if (matrix[i][j] > maxElement)
                {
                    maxElement = matrix[i][j];
                }
            }
            cout << "Максимальный элемент чётной строки " << i << ": " << maxElement << endl;
            sumEvenMax += maxElement;
        }
        else
        {
            int minElement = matrix[i][0];
            for (int j = 1; j < size; j++)
            {
                if (matrix[i][j] < minElement)
                {
                    minElement = matrix[i][j];
                }
            }
            cout << "Минимальный элемент нечётной строки " << i << ": " << minElement << endl;
            sumOddMin += minElement;
        }
    }


    cout << "Сумма наименьших элементов нечётных строк: " << sumOddMin << endl;
    cout << "Сумма наибольших элементов чётных строк: " << sumEvenMax << endl;


    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

