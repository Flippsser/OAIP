#include <iostream>
#include <string>
using namespace std;

// Функция для задачи 1: Сумма элементов ниже главной диагонали
int sumBelowMainDiagonal(int** array, int n)
{
    int sum = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            sum += array[i][j];
        }
    }
    return sum;
}

// Функция для задачи 2: Подсчет вхождений символа, указанного пользователем
int countCharInText(const string& text, char targetChar)
{
    int count = 0;
    for (char ch : text)
    {
        if (ch == targetChar)
        {
            ++count;
        }
    }
    return count;
}


void printMatrix(int** array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int c;
    do {
    cout << "Выберите задачу:\n1. Найти сумму элементов ниже главной диагонали\n2. Определить количество вхождений символа в тексте\n3. Выход\n";
    cin >> c;
    cin.ignore();  // Очистка буфера после ввода числа
    
        switch (c)
        {
        case 1: {
            int n;
            cout << "Введите размерность массива: ";
            cin >> n;

            int** array = new int* [n];
            for (int i = 0; i < n; ++i)
            {
                array[i] = new int[n];
            }

            cout << "Введите элементы массива:\n";
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    cin >> array[i][j];
                }
            }

            cout << "Ваш массив:\n";
            printMatrix(array, n);

            int sum = sumBelowMainDiagonal(array, n);
            cout << "Сумма элементов ниже главной диагонали: " << sum << endl;

            for (int i = 0; i < n; ++i)
            {
                delete[] array[i];
            }
            delete[] array;
            break;
        }
        case 2: {
            int numOfLines;
            cout << "Введите количество строк: ";
            cin >> numOfLines;
            cin.ignore();

            string text, line;
            cout << "Введите текст:\n";
            for (int i = 0; i < numOfLines; ++i)
            {
                getline(cin, line);
                text += line + '\n';
            }

            char targetChar;
            cout << "Введите символ для поиска: ";
            cin >> targetChar;

            int count = countCharInText(text, targetChar);
            cout << "Количество вхождений символа " << targetChar << ": " << count << endl;
            break;
        }
        case 3:break;
        }
     }while (c != 3);
        return 0;
}
