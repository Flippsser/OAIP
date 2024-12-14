#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int k, l, m, n, k1 = 0, m1 = 0, l1 = 0, n1 = 0;
    cout << "Введите k,l,m,n" << endl;
    cin >> k >> l >> m >> n;
    {//проверка на ошибки ввода
        for (int i = 1; i < 9; i++)
        {
            if (k == i)
            {
                k1++;
            }

        }
        if (k1 != 1)
        {
            cout << "error";
            return 0;
        }
        for (int i = 1; i < 9; i++)
        {
            if (m == i)
            {
                m1++;
            }

        }
        if (m1 != 1)
        {
            cout << "error";
            return 0;
        }

        for (int i = 1; i < 9; i++)
        {
            if (l == i)
            {
                l1++;
            }

        }
        if (l1 != 1)
        {
            cout << "error";
            return 0;
        }

        for (int i = 1; i < 9; i++)
        {
            if (n == i)
            {
                n1++;
            }

        }
        if (n1 != 1)
        {
            cout << "error";
            return 0;
        }
    }
    {//проверка коня
        {
            k = k + 3;
            l = l - 1;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k - 3;
            l = l + 1;
        }

        {
            k = k + 3;
            l = l + 1;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k - 3;
            l = l - 1;
        }

        {
            k = k - 1;
            l = l - 3;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k + 1;
            l = l + 3;
        }

        {
            k = k + 1;
            l = l - 3;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k - 1;
            l = l + 3;
        }

        {
            k = k - 1;
            l = l + 3;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k + 1;
            l = l - 3;
        }

        {
            k = k + 1;
            l = l + 3;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k - 1;
            l = l - 3;
        }

        {
            k = k - 3;
            l = l - 1;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k + 3;
            l = l + 1;
        }

        {
            k = k - 3;
            l = l + 1;
            if (k == m and l == n)
            {
                cout << "Угроза";
                return 0;
            }
            k = k + 3;
            l = l - 1;
        }

    }
    cout << "Угрозы нет";

    return 0;
}