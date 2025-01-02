#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int m = 0, number = 0, pr = 0;
    long fsize;
    char pd;
    FILE* fd;
    errno_t err;
    err = fopen_s(&fd, "b.txt", "r");
    if (err != 0)
    {
        perror("Ошибка открытия b.txt");
        return 1;
    }
    fseek(fd, 0L, SEEK_END);
    fsize = ftell(fd);
    fseek(fd, 0L, SEEK_SET);
    printf("Введите номер предложения: ");
    if (scanf_s("%d", &number) != 1) {
        printf("Ошибка ввода числа.\n");
        fclose(fd);
        return 1;
    }
    for (int k = 1; k <= fsize; k++)
    {
        fread((void*)&pd, sizeof(char), 1, fd);
        if (pd == '.') pr++;
        if ((number - 1) == pr) m++;
        if (number == pr)
        {
            long pos1 = k - m - 1;
            if (number != 1) pos1++;
            fseek(fd, pos1, SEEK_SET);
            printf("%d-е предложение: ", number);
            for (int i = 0; i <= m; i++)
            {
                fread((void*)&pd, sizeof(char), 1, fd);
                printf("%c", pd);
            }
            break;
        }
    }
    if (number > pr)
        printf("Такого номера нет");
    fclose(fd);
    return 0;
}