#include <iostream>
using namespace std;

float ret[4]; 

float findmax(float** arr, int n, int m)
{
    int max = arr[0][0], maxi = 0, maxj = 0, count = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxi = i;
                maxj = j;
                count = 1;
            }
            else if (arr[i][j] == max)
            {
                count++;
            }
        }
    }

    ret[0] = max;
    ret[1] = maxi;
    ret[2] = maxj;
    ret[3] = count;

    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n, m;

    cout << "Введите размер матрицы: ";
    cin >> n >> m;

    float** arr;
    arr = new float* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new float[m]; 

    cout << "Введите матрицу: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j]; 
        }
    }
    findmax(arr, n, m); 
    float max = ret[0], maxi = ret[1], maxj = ret[2], count = ret[3];
    cout << "Максимальный элемент: " << max << "[" << maxi + 1 << "]" << "[" << maxj + 1 << "]" << "\nОн встречается " << count << " раз"; // Вывод

    
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
